#include <iostream>
#include "parsing/symbol.h"

extern int yyparse();

int main(int argc, char** argv) {
  int ret = yyparse();
  if (ret == 0) std::cout << "Finished all file" << std::endl;
  return ret;
}