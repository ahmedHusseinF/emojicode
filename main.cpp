#include <iostream>

extern int yyparse();

int main(int argc, char** argv) {
  yyparse();
  std::cout << "Finished all file" << std::endl;
  return 0;
}