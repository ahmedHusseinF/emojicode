pre:
	rm -f build/* && bison -d -o build/emoji.c parsing/emoji.y && flex -o build/lexer.c lexing/emoji.l

run:
	make pre && g++ -std=c++11 -g -o parser.out build/emoji.c build/lexer.c parsing/symTable.cpp

wasm:
	make pre && emcc \
    -Os \
    --bind \
    -s STRICT=1 \
    -s MODULARIZE=1 \
    -s EXPORT_ES6=1 \
    -o gui/src/parser.js \
    build/emoji.c build/lexer.c parsing/symTable.cpp wasm.cpp parsing/symTable.cpp wasm.cpp

