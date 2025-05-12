all:
	bison -d -v parser.y
	flex lexer.l
	g++ parser.tab.c lex.yy.c utils/symbolTable.cpp utils/quadHandler.cpp -o compiler.exe

	