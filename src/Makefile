all:
	bison -d -v parser.y
	flex lexer.l
	g++ parser.tab.c lex.yy.c utils/symbolTable.hpp utils/QuadHandler.hpp utils/symbolTable.cpp utils/QuadHandler.cpp -o compiler.exe

	