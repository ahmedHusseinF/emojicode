pre:
	rm -f build/* && bison -d -o build/emoji.c parsing/emoji.y && flex -o build/lexer.c lexing/emoji.l

run:
	make pre && g++ -g -o parser.out build/emoji.c build/lexer.c 

wasm:
	make pre && emcc \
    -Os \
    --bind \
    -s STRICT=1 \
    -s MODULARIZE=1 \
    -s EXPORT_ES6=1 \
    -o gui/src/parser.js \
    build/emoji.c build/lexer.c wasm.cpp

