#include <iostream>
using namespace std;

const int MAX = 100;

class Node {
  string identifier, scope, type;
  int lineNo;
  Node* next;

 public:
  Node() { next = NULL; }

  Node(string key, string value, string type, int lineNo) {
    this->identifier = key;
    this->scope = value;
    this->type = type;
    this->lineNo = lineNo;
    next = NULL;
  }

  void print() {
    cout << "Identifier's Name:" << identifier << "\nType:" << type
         << "\nScope: " << scope << "\nLine Number: " << lineNo << endl;
  }

  friend class SymbolTable;
};

class SymbolTable {
  Node* head[MAX];

 public:
  SymbolTable() {
    for (int i = 0; i < MAX; i++) head[i] = NULL;
  }

  int hashf(string id);  // hash function
  bool insert(string id, string scope, string Type, int lineno);

  string find(string id);

  bool deleteRecord(string id);

  bool modify(string id, string scope, string Type, int lineno);
};