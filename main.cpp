#include <iostream>
#include "parsing/symbol.h"

extern int yyparse();

Scope* curr = nullptr;

int main(int argc, char** argv) {
  yyparse();
  std::cout << "Finished all file" << std::endl;
  return 0;
}