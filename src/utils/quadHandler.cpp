#include "quadHandler.hpp"
#include "ErrorManger.cpp"

int QuadHandler::lineNumber = 0;
void QuadHandler::writeToFile(operation op, symbol *arg1, symbol *arg2, symbol *result)
{
    string op_str = operationToString[op];
    string arg1_name = !arg1 ? "" : arg1->name;
    string arg2_name = !arg2 ? "" : arg2->name;
    string result_name = !result ? "" : " " + result->name;
    quad_file << op_str << result_name << " " << arg1_name << " " << arg2_name << " " << endl;
}

void QuadHandler::writeToFile(string command)
{
    quad_file << command << endl;
}

string QuadHandler::generateLabel()
{
    return "L" + to_string(labelCounter++);
}

int QuadHandler::typeRank(symbolType type)
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

void QuadHandler::implicitCast(symbol *arg1, symbol *arg2)
{

    symbolType type1 = arg1->type;
    symbolType type2 = arg2->type;
    if (type1 == symbolType::UNKNOWN || type2 == symbolType::UNKNOWN)
    {
        return;
    }
    if (type1 != symbolType::INTtype && type1 != symbolType::FLOATtype && type1 != symbolType::BOOLtype && type1 != symbolType::CHARtype)
    {
        // yyerror(("Invalid type " + symbolTypeName[type1] + " for operation.").c_str());
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, ("Invalid type " + symbolTypeName[type1] + " for operation."));
        return;
    }
    if (type2 != symbolType::INTtype && type2 != symbolType::FLOATtype && type2 != symbolType::BOOLtype && type2 != symbolType::CHARtype)
    {
        // yyerror(("Invalid type " + symbolTypeName[type2] + " for operation.").c_str());
        errorManager.add(ErrorType::TYPE, lineNumber, arg2->name, ("Invalid type " + symbolTypeName[type2] + " for operation."));
        return;
    }

    if (type1 == type2)
    {
        if (type1 == symbolType::BOOLtype)
        {
            arg1->type = symbolType::INTtype;
            arg2->type = symbolType::INTtype;
        }
        return;
    }
    if (typeRank(type1) < typeRank(type2))
    {
        arg2->type = type1;
        quad_file << "CAST " << arg2->name << " to " << symbolTypeName[type1] << endl;
    }
    else
    {
        arg1->type = type2;
        quad_file << "CAST " << arg1->name << " to " << symbolTypeName[type2] << endl;
    }
}

void QuadHandler::bitwiseCast(symbol *arg1, symbol *arg2)
{

    symbolType type1 = arg1->type;
    symbolType type2 = arg2->type;
    if (type1 == symbolType::UNKNOWN || type2 == symbolType::UNKNOWN)
    {
        return;
    }
    if (type1 != symbolType::INTtype && type1 != symbolType::BOOLtype)
    {
        // yyerror(("Invalid type " + symbolTypeName[type1] + " for operation.").c_str());
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, ("Invalid type " + symbolTypeName[type1] + " for operation."));
        return;
    }
    if (type2 != symbolType::INTtype && type2 != symbolType::BOOLtype)
    {
        // yyerror(("Invalid type " + symbolTypeName[type2] + " for operation.").c_str());
        errorManager.add(ErrorType::TYPE, lineNumber, arg2->name, ("Invalid type " + symbolTypeName[type2] + " for operation."));
        return;
    }

    if (type1 == type2)
        return;

    if (typeRank(type1) < typeRank(type2))
    {
        arg2->type = type1;
        quad_file << "CAST " << arg2->name << " to " << symbolTypeName[type1] << endl;
    }
    else
    {
        arg1->type = type2;
        quad_file << "CAST " << arg1->name << " to " << symbolTypeName[type2] << endl;
    }
}

symbol *QuadHandler::math_op(operation op, symbol *arg1, symbol *arg2)
{
    implicitCast(arg1, arg2);

    string resultName = "t" + to_string(tempVarCounter++);
    symbol *result = new symbol(resultName, arg1->type, 1, 1);
    tempVars.push_back(result);

    writeToFile(op, arg1, arg2, result);
    return result;
}

symbol *QuadHandler::bit_op(operation op, symbol *arg1, symbol *arg2)
{
    bitwiseCast(arg1, arg2);

    string resultName = "t" + to_string(tempVarCounter++);
    symbol *result = new symbol(resultName, arg1->type, 1, 1);
    tempVars.push_back(result);

    writeToFile(op, arg1, arg2, result);
    return result;
}

symbol *QuadHandler::logic_op(operation op, symbol *arg1, symbol *arg2)
{

    if (op == operation::Not)
    {
        if (arg1->type != symbolType::BOOLtype)
        {
            // yyerror("Invalid type for logical operation.");
            errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, "Invalid type for logical operation.");
            return NULL;
        }
    }
    else if (arg1->type != symbolType::BOOLtype || arg2->type != symbolType::BOOLtype)
    {
        // yyerror("Invalid type for logical operation.");
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, "Invalid type for logical operation.");
        return NULL;
    }

    string resultName = "t" + to_string(tempVarCounter++);
    symbol *result = new symbol(resultName, arg1->type, 1, 1);
    tempVars.push_back(result);

    writeToFile(op, arg1, arg2, result);
    return result;
}

symbol *QuadHandler::rel_op(operation op, symbol *arg1, symbol *arg2)
{

    implicitCast(arg1, arg2);

    string resultName = "t" + to_string(tempVarCounter++);
    symbol *result = new symbol(resultName, symbolType::BOOLtype, 1, 1);
    tempVars.push_back(result);

    writeToFile(op, arg1, arg2, result);
    return result;
}

void QuadHandler::assign_op(operation op, symbol *dest, symbol *src)
{
    if (op != operation::Assign)
    {
        implicitCast(dest, src);
    }
    else if (op == operation::Assign)
    {
        if (src->type == symbolType::UNKNOWN || dest->type == symbolType::UNKNOWN)
        {
            return;
        }
    }

    if (dest->type == symbolType::VOIDtype || dest->type == symbolType::CONSTtype)
    {
        // yyerror("Can't assign to void type.");
        errorManager.add(ErrorType::TYPE, lineNumber, dest->name, "Can't assign to void type.");
        return;
    }
    if (src->type == symbolType::VOIDtype || src->type == symbolType::CONSTtype)
    {
        // yyerror("Can't assign void type.");
        errorManager.add(ErrorType::TYPE, lineNumber, src->name, "Can't assign void type.");
        return;
    }

    if (src->type == symbolType::STRINGtype && dest->type == symbolType::STRINGtype)
    {
        writeToFile(op, src, NULL, dest);
    }
    else if ((src->type == symbolType::STRINGtype && dest->type != symbolType::STRINGtype) || (src->type != symbolType::STRINGtype && dest->type == symbolType::STRINGtype))
    {
        // yyerror("Invalid type for assignment.");
        errorManager.add(ErrorType::TYPE, lineNumber, src->name, "Invalid type for assignment.");
        return;
    }
    else
    {
        if (src->type != dest->type)
        {
            quad_file << "CAST " << src->name << " to " << symbolTypeName[dest->type] << endl;
        }
        src->type = dest->type;
        symbol *temp;
        switch (op)
        {
        case operation::Add_assign:
            temp = math_op(operation::Plus, dest, src);
            writeToFile(operation::Assign, temp, NULL, dest);
            break;
        case operation::Sub_assign:
            temp = math_op(operation::Minus, dest, src);
            writeToFile(operation::Assign, temp, NULL, dest);
            break;
        case operation::Mul_assign:
            temp = math_op(operation::Mul, dest, src);
            writeToFile(operation::Assign, temp, NULL, dest);
            break;
        case operation::Div_assign:
            temp = math_op(operation::Div, dest, src);
            writeToFile(operation::Assign, temp, NULL, dest);
            break;
        case operation::Mod_assign:
            temp = math_op(operation::Mod, dest, src);
            writeToFile(operation::Assign, temp, NULL, dest);
            break;

        default:
            writeToFile(op, src, NULL, dest);
            break;
        }
    }
}

symbol *QuadHandler::unary_op(operation op, symbol *arg1)
{
    symbolType type1 = arg1->type;
    if (type1 == symbolType::UNKNOWN)
    {
        return NULL;
    }
    if ((type1 != symbolType::INTtype && type1 != symbolType::FLOATtype) || arg1->isConst)
    {
        // yyerror(("Invalid type " + symbolTypeName[type1] + " for operation.").c_str());
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, ("Invalid type " + symbolTypeName[type1] + " for operation."));
        return NULL;
    }

    writeToFile(op, arg1, NULL, NULL);
    return arg1;
}

void QuadHandler::jump_cond_op(symbol *arg1, string label, bool onTrue)
{
    if (arg1->type == symbolType::UNKNOWN)
    {
        return;
    }
    if (arg1->type == symbolType::VOIDtype)
    {
        // yyerror("Invalid type for conditional jump.");
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, "Invalid type for conditional jump.");
        return;
    }

    string command = "jmp " + label + " on " + arg1->name + " " + (onTrue ? "true" : "false");
    writeToFile(command);
}

void QuadHandler::jump_uncond_op(string label)
{
    string command = "jmp " + label;
    writeToFile(command);
}

void QuadHandler::declare_func_op(symbol *funcPrototype, vector<symbol *> args)
{
    string command = "proc " + symbolTypeName[funcPrototype->type] + " " + funcPrototype->name + " ";
    for (auto arg : args)
    {
        command += symbolTypeName[arg->type] + " " + arg->name + " ";
    }
    writeToFile(command);
}

// cast arg2 to arg1
bool QuadHandler::tryCast(symbol *arg1, symbolType type)
{
    if (arg1->type == type)
        return true;
    if (arg1->type == symbolType::INTtype || arg1->type == symbolType::BOOLtype || arg1->type == symbolType::FLOATtype || arg1->type == symbolType::CHARtype)
    {
        if (type == symbolType::INTtype || type == symbolType::BOOLtype || type == symbolType::FLOATtype || type == symbolType::CHARtype)
        {
            quad_file << "CAST " << arg1->name << " to " << symbolTypeName[type] << endl;
            return true;
        }
    }
    return false;
}

void QuadHandler::return_op(symbol *arg1, symbolType returnType)
{
    if (!arg1)
    {
        if (returnType != symbolType::VOIDtype)
        {
            // yyerror("Function return type is not void.");
            errorManager.add(ErrorType::TYPE, lineNumber, "return", "Function return type is not void.");
            return;
        }
        writeToFile("return");
        return;
    }
    if (returnType == symbolType::UNKNOWN)
    {
        // yyerror("Return cannot be outside function.");
        errorManager.add(ErrorType::TYPE, lineNumber, "return", "Return cannot be outside function.");
        return;
    }
    else if (!tryCast(arg1, returnType))
    {
        // yyerror("Invalid return type. Cannot cast value to function return type.");
        errorManager.add(ErrorType::TYPE, lineNumber, arg1->name, "Invalid return type. Cannot cast value to function return type.");
        return;
    }
    string command = "return " + arg1->name + "\n\n";
    writeToFile(command);
}

symbol *QuadHandler::call_func_op(symbol *funcPrototype, vector<symbol *> args)
{
    symbol *result = new symbol("t" + to_string(tempVarCounter++), funcPrototype->type, 1, 1);
    tempVars.push_back(result);
    string command = "call " + funcPrototype->name + " " + result->name + " ";
    for (auto arg : args)
    {
        command += arg->name + " ";
    }
    writeToFile(command);
    return result;
}

void QuadHandler::cleanUp()
{
    for (auto tempVar : tempVars)
    {
        if (tempVar)
            delete tempVar;
    }
}