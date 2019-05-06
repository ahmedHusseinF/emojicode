pre:
	bison -d -o build/emoji.cpp parsing/emoji.y && flex -o build/lexer.cpp lexing/emoji.l

build:
	make pre && g++ -g -o parser.out build/emoji.cpp build/lexer.cpp main.cpp

wasm:
	make pre && emcc \
    -Os \
    --bind \
    -s STRICT=1 \
    -s MODULARIZE=1 \
    -s EXPORT_ES6=1 \
    -o gui/parser.js \
    build/emoji.cpp build/lexer.cpp wasm.cpp

