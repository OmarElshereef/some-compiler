#include "symbolTable.hpp"
#include "ErrorManger.cpp"
#include "includes.hpp"
#include <vector>
#pragma once

symbolType symbolTable::currentType = UNKNOWN;
bool symbolTable::isCurrentConst = false;

symbolTable::symbolTable()
{
    this->scope = 0;
}
int symbolTable::lineNumber = 0;

// direction = true means enter a new scope downward, false means leave the current scope and go to the parent scope
void symbolTable::changeScope(bool direction)
{
    if (direction == 1)
    {
        symbolTable *newTable = new symbolTable();
        newTable->parent = current;
        symbolTableAdj[current->scope].push_back(newTable);
        current = newTable;
        symbolTableAdj.push_back(vector<symbolTable *>());
        numScopes++;
        newTable->scope = numScopes;
    }
    else
    {
        current = current->parent;
    }
    cout << "Entered new scope: " << current->scope << endl;
}

symbol *symbolTable::addSymbol(string name, symbolType type, bool isConst, bool isInitialization)
{

    if (isConst && !isInitialization)
    {
        errorManager.add(
            ErrorType::SEMANTIC, lineNumber, name,
            "Constant " + name + " must be initialized at declaration.");
        return nullptr;
    }

    symbol *existing = findSymbol(name);
    if (existing)
    {

        if (current->symbols.count(name))
        {
            errorManager.add(
                ErrorType::SEMANTIC, lineNumber, name,
                "Symbol " + name + " already exists in this scope.");
        }
        else
        {
            errorManager.add(
                ErrorType::SEMANTIC, lineNumber, name,
                "Symbol " + name + " already declared in an outer scope; shadowing is not allowed.");
        }
        return nullptr;
    }

    symbol *newSym = new symbol(name, type, isConst, isInitialization);
    current->symbols[name] = newSym;
    return newSym;
}

symbol *symbolTable::updateSymbol(string name)
{
    symbol *sym = findSymbol(name);
    if (!sym)
    {
        errorManager.add(
            ErrorType::SEMANTIC, lineNumber, name,
            "Symbol " + name + " must be declared before use.");
        return NULL;
    }
    if (sym->isConst)
    {
        errorManager.add(
            ErrorType::SEMANTIC, lineNumber, name,
            "Symbol " + name + " is a constant and cannot be updated.");
        return NULL;
    }
    sym->isInitializated = true;
    return sym;
}

symbol *symbolTable::setUsed(symbol *sym)
{
    sym->isUsed = true;
    return sym;
}

symbol *symbolTable::findSymbol(string name)
{
    symbolTable *root = current;
    while (root != NULL)
    {
        auto foundSymbol = root->symbols.find(name);
        if (foundSymbol != root->symbols.end())
        {
            return foundSymbol->second;
        }
        root = root->parent;
    }
    return NULL;
}

symbol *symbolTable::useSymbol(string name)
{
    symbol *sym = findSymbol(name);
    if (!sym)
    {
        errorManager.add(
            ErrorType::SEMANTIC, lineNumber, name,
            "Symbol " + name + " is not declared.");
        return NULL;
    }
    if (!sym->isInitializated)
    {
        errorManager.add(
            ErrorType::SEMANTIC, lineNumber, name,
            "Symbol " + name + " is not initialized.");
        return NULL;
    }
    sym->isUsed = true;
    return sym;
}

void symbolTable::printSymbolTable(symbolTable *root)
{
    cout << "\n---------------\n\nScope " << root->scope << ":" << endl;
    for (auto it2 = root->symbols.begin(); it2 != root->symbols.end(); it2++)
    {
        if (it2->second->isConst)
            cout << "const ";
        cout << symbolTypeName[it2->second->type] << " " << it2->second->name << endl;
        if (it2->second->isUsed == false)
        {
            string error = "Symbol ** " + it2->second->name + " ** is declared but not used.";
            yywarn(error.c_str());
        }
    }
    cout << endl
         << endl;
    for (auto it = symbolTableAdj[root->scope].begin(); it != symbolTableAdj[root->scope].end(); it++)
    {
        printSymbolTable(*it);
    }
}

symbolTable::~symbolTable()
{
}

void symbolTable::cleanUp()
{
    for (int i = 0; i <= numScopes; i++)
    {
        for (auto i : symbolTableAdj[i])
        {
            if (i)
                delete i;
        }
    }
}