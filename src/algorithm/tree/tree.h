
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
  bool isLeaf;

 public:
  BTree(int m, bool isLeaf);

  ~BTree();

  void addNode(BNode<T> *n);
  void deleteNode(string key);
  BNode<T> *search(string key);
  vector<BNode<T> *> traverse();
  int getRank() { return rank; }
  vector<BNode<T> *> *getEntities() { return entities; }
  vector<BTree<T> *> *getChildren() { return children; }
};
void testSearch();
#pragma endregion