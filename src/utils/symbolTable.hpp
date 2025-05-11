#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "includes.hpp"

using namespace std;

#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

enum symbolType
{
    LINTtype,
    LLINTtype,
    DOUBLEtype,
    FLOATtype,
    INTtype,
    BOOLtype,
    CHARtype,
    STRINGtype,
    CONSTtype,
    VOIDtype,
    UNKNOWN
};
const vector<string> symbolTypeName = {"LINT", "LLINT", "DOUBLE", "FLOAT", "INT", "BOOL", "CHAR", "STRING", "CONST", "VOID", "UNKNOWN"};

int typeRank(symbolType type)
{
    switch (type)
    {
    case CHARtype:
        return 0;
    case BOOLtype:
        return 1;
    case INTtype:
        return 2;
    case FLOATtype:
        return 3;
    case DOUBLEtype:
        return 4;
    case LLINTtype:
        return 5;
    case LINTtype:
        return 6;
    default:
        return -1; // Unknown or unsupported
    }
}

class constNode
{
public:
    constNode(symbolType type)
    {
        this->type = type;
    }
    constNode(symbolType type, string value)
    {
        this->type = type;
        switch (type)
        {
        case INTtype:
            this->ival = stoi(value);
            break;
        case LINTtype:
            this->lival = stol(value);
            break;
        case LLINTtype:
            this->llival = stoll(value);
            break;
        case BOOLtype:
            if (value == "true")
            {
                this->bval = true;
            }
            else if (value == "false")
            {
                this->bval = false;
            }
            else
            {
                int x;
                x = stoi(value);
                if (x != 0)
                {
                    this->bval = true;
                }
                else
                {
                    this->bval = false;
                }
            }
            break;
        case FLOATtype:
            this->fval = stof(value);
            break;
        case DOUBLEtype:
            this->dval = stod(value);
            break;
        case CHARtype:
            this->cval = value[0];
            break;
        case STRINGtype:
            this->sval = value;
            break;
        case VOIDtype:
            this->pval = NULL;
            break;
        // case CONSTtype:
        // case UNKNOWN:
        default:
            break;
        }
    }
    constNode()
    {
        type = UNKNOWN;
    }
    symbolType type;
    union
    {
        char cval;
        string sval;
        int ival;
        long int lival;
        long long int llival;
        bool bval;
        float fval;
        double dval;
        void *pval;
    };
    ~constNode() {}
};

class symbol
{
public:
    string name;
    symbolType type;
    bool isConst;
    bool isInitializated;
    bool isUsed;

    symbol()
    {
        name = "";
        isConst = false;
        isInitializated = false;
        isUsed = false;
    }

    symbol(string name, symbolType type, bool isConst, bool isInitializated, bool isUsed = false)
    {
        this->name = name;
        this->type = type;
        this->isConst = isConst;
        this->isInitializated = isInitializated;
        this->isUsed = isUsed;
    }
};

struct nonConstNode
{
    char *name;
    int noOperands;
    struct myNode *operands[1];
};

struct node
{
    bool isConst;
    union
    {
        struct nonConstNode nonConstNode;
        constNode constNode;
    };
};

class symbolTable
{
public:
    static symbolTable *current;
    static vector<vector<symbolTable *>> symbolTableAdj;
    static int numScopes;
    int scope;
    map<string, symbol *> symbols;
    symbolTable *parent;

    symbolTable();

    // direction = true means enter a new scope downward, false means leave the current scope and go to the parent scope
    void changeScope(bool direction);

    struct symbol *addOrUpdateSymbol(string name, symbolType type, symbol *value, bool isConst, bool isInitialization);

    struct symbol *addSymbol(string name, symbolType type, bool isConst, bool isInitialization);

    struct symbol *updateSymbol(string name);
    symbol *setUsed(symbol *sym);

    struct symbol *findSymbol(string name);

    void printSymbolTable(symbolTable *table);

    static void cleanUp();

    ~symbolTable();
};

#endif