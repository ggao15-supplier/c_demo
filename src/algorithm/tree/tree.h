
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
  BTree(int m, bool isLeaf);

  ~BTree();
  /**
   *1. m阶的BTree
   *2. 只有一个根节点
   *3. 根节点的子节点的数量[2,m],根节点数据的数量:[2,m-1]
   *4. 非根子节点的子节点数量[m/2,m],数据的数量[m/2,m-1]
   *5.叶子节点没有子节点,只有数据,数据数量[m/2,m-1],并且叶子节点必须在同一高度上
   *6. 数据为 key-value 形式,同一层上所有节点的key从左到右依次递增
   *7. 在一个数据点的左边的子树的key都小于该数据的key
   *8.在一个数据点的右边的子树的key都大于该数据的key
   *
   **/
  void addNode(BNode<T> *n);
  void deleteNode(string key);
  BNode<T> *search(string key);
  vector<BNode<T> *> traverse();
  int getRank() { return rank; }
  vector<BNode<T> *> *getEntities() { return entities; }
  vector<BTree<T> *> *getChildren() { return children; }
};
void testCreateBTree();
void testSearch();

#pragma endregion