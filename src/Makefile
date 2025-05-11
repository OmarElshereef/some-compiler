all:
	bison -d -v parser.y
	flex lexer.l
	g++ parser.tab.c lex.yy.c -o compiler.exe

	