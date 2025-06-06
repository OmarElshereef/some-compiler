#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "includes.hpp"
#pragma once
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
    UNKNOWN,
    ERROR
};
struct LoopLabels
{
    std::string startLabel;
    std::string endLabel;
};
const vector<string> symbolTypeName = {"LINT", "LLINT", "DOUBLE", "FLOAT", "INT", "BOOL", "CHAR", "STRING", "CONST", "VOID", "UNKNOWN"};

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
        constNode constantNode;
    };
};

class symbolTable
{
public:
    static symbolTable *current;
    static vector<vector<symbolTable *>> symbolTableAdj;
    static int numScopes;
    static int lineNumber;
    static symbolType currentType;
    static bool isCurrentConst;
    int scope;
    map<string, symbol *> symbols;
    symbolTable *parent;

    symbolTable();

    // direction = true means enter a new scope downward, false means leave the current scope and go to the parent scope
    void changeScope(bool direction);

    struct symbol *addSymbol(string name, symbolType type, bool isConst, bool isInitialization);

    struct symbol *updateSymbol(string name);
    symbol *setUsed(symbol *sym);

    struct symbol *findSymbol(string name);

    struct symbol *useSymbol(string name);

    void printSymbolTable(symbolTable *table);

    static void cleanUp();

    ~symbolTable();
};

#endif