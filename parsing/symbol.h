

#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <unordered_map>

#define INT 1
#define STRING 2
#define BOOLEAN 3

enum OPERATION_RETURN {
  SUCCESSFUL_INSERTION,
  DUPLICATE_INSERTION,
  FAILED_TO_INSERTION,

  SUCCESSFUL_UPDATE,
  SYMBOL_NOT_FOUND,
  SEMANTIC_ERROR_TYPE_INCOMPATIBLE,
  SEMANTIC_ERROR_ATTEMPT_CHANGING_CONSTANT,
};

typedef union valueType {
  int Number;
  char *str;
} Values;

struct Symbol {
  int type;  // 1-->int, 2-->char*, 3--> boolean
  bool isConst;
  Values value;
};

struct Scope {
  std::unordered_map<char *, Symbol> currentLockup;
  Scope *above;
};

#endif