#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

enum ErrorType
{
    SYNTAX,
    SEMANTIC,
    TYPE,
    WARNING
};

struct CompileError
{
    ErrorType type;
    int line;
    std::string token;
    std::string message;
};

class ErrorManager
{
public:
    std::vector<CompileError> errors;

    ErrorManager() {}

    void add(ErrorType type, int line, const std::string &token, const std::string &msg)
    {
        errors.push_back({type, line, token, msg});
    }

    void reportAll()
    {
        int errorCount = errors.size();
        for (const auto &err : errors)
        {
            std::string typeStr;
            switch (err.type)
            {
            case SYNTAX:
                typeStr = "Syntax Error";
                break;
            case SEMANTIC:
                typeStr = "Semantic Error";
                break;
            case TYPE:
                typeStr = "Type Error";
                break;
            case WARNING:
                typeStr = "Warning";
                errorCount--;
                break;
            }

            std::cerr << "[" << typeStr << "] Line " << err.line
                      << " near '" << err.token << "': " << err.message << "\n";
        }

        if (errorCount > 0)
        {
            std::cerr << "\nCompilation failed with " << errorCount << " error(s).\n";
            exit(1);
        }
    }
};
extern ErrorManager errorManager;

#endif // ERROR_MANAGER_H