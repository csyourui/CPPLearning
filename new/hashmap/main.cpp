/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-24
 */
#include <stdio.h>
#include <stdlib.h>

static int hash(const int& key) { return (key % 19); }

class HashNode {
 public:
  int _key;
  int _value;
  HashNode* next;

  HashNode(int key, int value) {
    _key = key;
    _value = value;
    next = nullptr;
  }
  ~HashNode() {}
};

class HashMap {
 public:
  explicit HashMap(int size) : _size(size) {
    table = new HashNode*[_size];
    for (unsigned i = 0; i < _size; i++) table[i] = nullptr;
  }
  ~HashMap() {
    for (unsigned i = 0; i < _size; i++) {
      HashNode* currentNode = table[i];
      while (currentNode) {
        HashNode* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
      }
    }
    delete table;
  }
  bool insert(const int& key, const int& value);
  int& find(const int& key);

 private:
  HashNode** table;
  unsigned int _size;
  int ValueNULL;
};

bool HashMap::insert(const int& key, const int& value) {
  int index = hash(key) % _size;
  HashNode* node = new HashNode(key, value);
  node->next = table[index];
  table[index] = node;
  return true;
}

int& HashMap::find(const int& key) {
  unsigned index = hash(key) % _size;
  if (table[index] == nullptr) {
    return ValueNULL;
  } else {
    HashNode* node = table[index];
    while (node) {
      if (node->_key == key) return node->_value;
      node = node->next;
    }
  }
  return ValueNULL;
}

int main() {
  HashMap m(100);
  m.insert(1995, 11);
  m.insert(11, 30);
  m.insert(30, 25);
  printf("after insert: \n");
  printf("find 1995: %d\n", m.find(1995));
  printf("find 11: %d\n", m.find(11));
  printf("find 30: %d\n", m.find(30));
}
