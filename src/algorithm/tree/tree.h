
#include <list>
#include <string>
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
};

template <class T>
class BTree {
 private:
  BNode<T> entity;

 public:
  BTree(/* args */);
  ~BTree();
};

#pragma endregion