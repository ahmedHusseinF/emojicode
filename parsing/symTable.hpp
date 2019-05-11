#include <string.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
using namespace std;

const int MAX = 500;

typedef union valueType {
  int Number;
  char* str;
} Values;

enum Status {
  SUCCESSFUL_INSERTION,
  DUPLICATE_INSERTION,
  FAILED_TO_INSERTION,

  SUCCESSFUL_UPDATE,
  SYMBOL_NOT_FOUND,
  SEMANTIC_ERROR_TYPE_INCOMPATIBLE,
  SEMANTIC_ERROR_ATTEMPT_CHANGING_CONSTANT,

  SUCCESSFUL_DELETE,
  FAILED_TO_DELETE,
  FAILED_TO_UPDATE,
};

enum Types { INT, STRING, BOOLEAN };

class Node {
  string identifier;
  int scope;  // unique
  int depth;
  Types type;
  bool isConst;
  Values val;
  Node* next;

 public:
  Node() { next = nullptr; }

  Node(string key, int scope, int depth, Types type, Values val, bool isConst) {
    this->identifier = key;
    this->scope = scope;
    this->type = type;
    this->depth = depth;
    this->val = val;
    this->isConst = isConst;
    next = nullptr;
  }

  void print() {
    cout << identifier << '\t' << type << '\t' << scope << '\t' << depth
         << '\t';

    if (type == Types::STRING) {
      cout << val.str;
    } else {
      cout << val.Number;
    }

    cout << endl;
  }

  friend class SymbolTable;
};

class SymbolTable {
  Node* head[MAX];

 public:
  SymbolTable() {
    for (int i = 0; i < MAX; i++) head[i] = nullptr;
  }

  int hashf(string id);  // hash function
  Status insert(string id, int scope, int depth, Types Type, Values val, bool);

  Node* find(string id);

  int getInt(string id, int depth);
  bool getBool(string id, int depth);
  char* getString(string id, int depth);

  Status deleteRecord(string id);

  Status modify(string id, Types Type, Values val, int scope);

  void print();
};