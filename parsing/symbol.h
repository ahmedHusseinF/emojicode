#pragma once

#ifndef _SYMBOL_H
#define _SYMBOL_H 1

#include <iostream>
#include <map>
#include <string>

struct Symbol {
  bool constant;
  int scope;  // 0 for global
  std::string id;
  std::string value;
};

class SymbolTable {
 private:
  std::map<std::string, Symbol> symbols;

 public:
  SymbolTable();
  void addIntSymbol(bool, int, int, std::string);
  void addStringSymbol(bool, int, std::string, std::string);
  std::string getSymbolValue(std::string);
  void printTable();
  ~SymbolTable();
};

#endif