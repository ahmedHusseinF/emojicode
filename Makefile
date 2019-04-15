all:
	bison -d -o build/emoji.cpp parsing/emoji.y && lex -o build/lexer.cpp lexing/emoji.l && g++ -o parser.out build/emoji.cpp build/lexer.cpp parsing/symbol.cpp main.cpp