#pragma once

#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <iostream>
#include <map>
#include <string>

enum Types { INT, STRING, FLOAT };

enum Status {
  SUCCESS,
  DUPLICATE,
  FAIL,
  TYPE_MISMATCH,
  CONST_REDECLARATION,
  NOT_FOUND,
};

typedef union value {
  float floaty;
  int integer;
  std::string str;
} Values;

struct Symbol {
  bool constant;
  std::string name;
  Types type;
  Values value;
};

struct Scope {
  std::map<std::string, Symbol> table;
  Scope *parent;
};

#endif