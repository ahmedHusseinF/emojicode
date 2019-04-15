#include "symbol.h"

SymbolTable::SymbolTable() {}

void SymbolTable::addIntSymbol(bool c, int s, int v, std::string id) {
  Symbol a;

  a.id = id;
  a.constant = c;
  a.scope = s;
  a.value = std::to_string(v);
  this->symbols.insert(std::pair<std::string, Symbol>(id, a));
}

void SymbolTable::addStringSymbol(bool c, int s, std::string v,
                                  std::string id) {
  Symbol a;

  a.id = id;
  a.constant = c;
  a.scope = s;
  a.value = v;
  this->symbols.insert(std::pair<std::string, Symbol>(id, a));
}

std::string SymbolTable::getSymbolValue(std::string id) {
  auto sym = this->symbols.at(id);

  return sym.value;
}

void SymbolTable::printTable() {
  for (auto& x : symbols) {
    std::cout << x.first << " : " << x.second.constant << x.second.scope
              << x.second.value << std::endl;
  }
}

SymbolTable::~SymbolTable() { symbols.clear(); }