#include "symTable.hpp"

char* sanitizeString(char* str) {
  // replace all " with nothing

  string x = string(str);

  if (x.length() > 2) {
    x.erase(x.begin() + 0);
    x.pop_back();
  }

  return strdup(x.c_str());
}

// Function to modify an identifier
Status SymbolTable::modify(string id, Types t, Values v, int depth) {
  int index = hashf(id);
  Node* start = head[index];

  if (start == nullptr) return Status::SYMBOL_NOT_FOUND;

  while (start != NULL) {
    if (start->identifier == id) {
      if (start->isConst == true) {
        return Status::SEMANTIC_ERROR_ATTEMPT_CHANGING_CONSTANT;
      }
      if (start->type != t) {
        return Status::SEMANTIC_ERROR_TYPE_INCOMPATIBLE;
      }
      if (start->depth != depth) {
        return Status::FAILED_TO_UPDATE;
      }
      if (t == Types::STRING) {
        v.str = sanitizeString(v.str);
      }
      start->val = v;
      cout << "\n" << id << " modified\n";
      return Status::SUCCESSFUL_UPDATE;
    }

    start = start->next;
  }

  return Status::SYMBOL_NOT_FOUND;  // id not found
}

// Function to delete an identifier
Status SymbolTable::deleteRecord(string id) {
  int index = hashf(id);
  Node* tmp = head[index];
  Node* par = head[index];

  // no identifier is present at that index
  if (tmp == NULL) {
    return Status::SYMBOL_NOT_FOUND;
  }

  // only one identifier is present
  if (tmp->identifier == id && tmp->next == NULL) {
    tmp->next = NULL;
    delete tmp;
    return Status::SUCCESSFUL_DELETE;
  }

  while (tmp->identifier != id && tmp->next != NULL) {
    par = tmp;
    tmp = tmp->next;
  }

  if (tmp->identifier == id && tmp->next != NULL) {
    par->next = tmp->next;
    tmp->next = NULL;
    delete tmp;
    return Status::SUCCESSFUL_DELETE;
  }

  // delete at the end
  else {
    par->next = NULL;
    tmp->next = NULL;
    delete tmp;
    return Status::SUCCESSFUL_DELETE;
  }

  return Status::FAILED_TO_DELETE;
}

// Function to find an identifier
Node* SymbolTable::find(string id) {
  int index = hashf(id);
  Node* start = head[index];

  if (start == nullptr) return nullptr;

  while (start != NULL) {
    if (start->identifier == id) {
      start->print();
      return start;
    }

    start = start->next;
  }

  return nullptr;  // not found
}

// Function to insert an identifier
Status SymbolTable::insert(string id, int scope, int depth, Types type,
                           Values val, bool isConst) {
  int index = hashf(id);

  if (type == Types::STRING) {
    val.str = sanitizeString(val.str);
  }
  Node* p = new Node(id, scope, depth, type, val, isConst);

  auto existNode = this->find(id);

  if (existNode != nullptr && existNode->scope == scope &&
      existNode->depth == depth) {
    return Status::DUPLICATE_INSERTION;
  }

  if (head[index] == nullptr) {
    head[index] = p;
    cout << "\n" << id << " inserted\n";

    return Status::SUCCESSFUL_INSERTION;
  } else {
    Node* start = head[index];
    while (start->next != nullptr) start = start->next;

    start->next = p;
    cout << "\n" << id << " inserted\n";

    return SUCCESSFUL_INSERTION;
  }

  return Status::FAILED_TO_INSERTION;
}

int SymbolTable::hashf(string id) {
  int asciiSum = 0;

  for (int i = 0; i < id.length(); i++) {
    asciiSum = asciiSum + id[i];
  }

  return (asciiSum % 100);
}

void SymbolTable::print() {
  cout << "\nId"
       << "\tType"
       << "\tScope"
       << "\tDepth"
       << "\tValue" << endl;
  for (int i = 0; i < MAX; i++) {
    if (this->head[i] != nullptr) {
      this->head[i]->print();
      auto tmp = this->head[i]->next;
      while (tmp != nullptr) {
        tmp->print();
        tmp = tmp->next;
      }
    }
  }
}