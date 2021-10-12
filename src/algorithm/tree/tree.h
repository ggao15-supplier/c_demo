
#include <string>
#include <vector>
using namespace std;
#pragma region 普通二叉树

template <typename T>
struct Node {
  T data;
  Node<T> *left = NULL;
  Node<T> *right = NULL;
};
void testParse();
void testCreate();
void testTreeSort();
#pragma endregion

#pragma region AVL二叉树
template <class T>
struct AVLNode {
  T data;
  int height;
  AVLNode<T> *left = NULL;
  AVLNode<T> *right = NULL;
};
void testCreateAVL();
#pragma endregion

#pragma region B + Tree
template <class T>
struct BNode {
  string key;
  T value;
  int compare(BNode *n) {
    if (n == NULL) {
      return 1;
    }
    if (key == n->key) {
      return 0;
    } else if (key > n->key) {
      return 1;
    } else {
      return -1;
    }
  }
};

template <class T>
class BTree {
 private:
  int rank;
  vector<BNode<T> *> *entities;
  vector<BTree<T> *> *children;

 public:
  BTree(int m) {
    this->rank = m;
    this->children = new vector<BNode<T> *>;
    this->entities = new vector<BNode<T> *>;
  }

  ~BTree() {
    if (this->entities != nuLL) {
      if (!this->entities->empty()) {
        for (int i = 0; i < this->entities->size; i++) {
          delete (*this->entities)[i];
        }
        this->entities->clear();
      }
      delete this->entities;
    }

    if (this->children != nuLL) {
      if (!this->children->empty()) {
        for (int i = 0; i < this->children->size; i++) {
          delete (*this->children)[i];
        }
        this->children->clear();
      }
      delete this->children;
    }
  }

  void addNode(BNode<T> *n);
  void deleteNode(string key);
  vector<BNode<T> *> search(string key);
};

#pragma endregion