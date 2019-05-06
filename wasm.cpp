#include <emscripten/bind.h>
#include <iostream>
#include <string>

extern int yyparse();

using namespace std;
using namespace emscripten;

int compileText(string text) {
  cout << text << endl;
  return 0;
}

EMSCRIPTEN_BINDINGS(emojicode) {
  emscripten::function("compileText", &compileText);
}