#include <iostream>
#include <string>
#include <vector>

#include "tree.h"
using namespace std;

/**
 * 获取data在middle 数组中的index
 * */
template <typename T>
int index(vector<T>* list, T value) {
  for (int i = 0; i < list->size(); i++) {
    if ((*list)[i] == value) {
      return i;
    }
  }
  return -1;
}
/**
 * 通过递归来遍历 middle 数组中的数据,比较位置来创建node节点
 * */
template <typename T>
void parseMiddle(Node<T>* tree, vector<T>* middle, T data) {
  int currentIndex = index(middle, data);
  int middleIndex = index(middle, tree->data);
  if (currentIndex < middleIndex) {
    if (tree->left == NULL) {
      tree->left = new Node<T>;
      tree->left->data = data;
      tree->left->left = NULL;
      tree->left->right = NULL;
      return;
    } else {
      parseMiddle(tree->left, middle, data);
    }

  } else {
    if (tree->right == NULL) {
      tree->right = new Node<T>;
      tree->right->data = data;
      tree->right->left = NULL;
      tree->right->right = NULL;
      return;
    } else {
      parseMiddle(tree->right, middle, data);
    }
  }
}

/**
 * 使用 前序数组和中序数组 创建tree
 * **/
template <typename T>
void createTree(Node<T>* tree, vector<T>* middle, vector<T>* pre) {
  for (int i = 0; i < pre->size(); i++) {
    T data = (*pre)[i];
    if (i == 0) {
      tree->data = data;
      tree->left = NULL;
      tree->right = NULL;
    } else {
      parseMiddle(tree, middle, data);
    }
  }
}

template <typename T>
void preParseTree(Node<T>* tree, vector<T>* v) {
  if (v == NULL || tree == NULL) return;
  v->push_back(tree->data);
  preParseTree(tree->left, v);
  preParseTree(tree->right, v);
}
template <typename T>
void middleParseTree(Node<T>* tree, vector<T>* v) {
  if (v == NULL || tree == NULL) return;
  middleParseTree(tree->left, v);
  v->push_back(tree->data);
  middleParseTree(tree->right, v);
}
template <typename T>
void neoParseTree(Node<T>* tree, vector<T>* v) {
  if (v == NULL || tree == NULL) return;
  neoParseTree(tree->left, v);
  neoParseTree(tree->right, v);
  v->push_back(tree->data);
}
void testParse() {
  Node<int>* tree = new Node<int>;
  tree->data = 1;
  Node<int>* t1_l = new Node<int>;
  t1_l->data = 2;
  Node<int>* t1_r = new Node<int>;
  t1_r->data = 3;
  Node<int>* t2_l = new Node<int>;
  t2_l->data = 4;
  Node<int>* t2_r = new Node<int>;
  t2_r->data = 5;
  Node<int>* t3_l = new Node<int>;
  t3_l->data = 6;
  Node<int>* t3_r = new Node<int>;
  t3_r->data = 7;

  tree->left = t1_l;
  tree->right = t1_r;
  t1_l->left = t2_l;
  t1_l->right = t2_r;
  t1_r->left = t3_l;
  t1_r->right = t3_r;
  t2_l->left = NULL;
  t2_r->left = NULL;
  t3_l->left = NULL;
  t3_r->left = NULL;
  vector<int>* v = new vector<int>;

  cout << "**********先序*************" << endl;
  preParseTree(tree, v);
  for (vector<int>::iterator item = v->begin(); item != v->end(); item++) {
    cout << (*item) << endl;
  }
  cout << "**********中序*************" << endl;
  v->clear();
  middleParseTree(tree, v);
  for (vector<int>::iterator item = v->begin(); item != v->end(); item++) {
    cout << (*item) << endl;
  }
  cout << "**********后序*************" << endl;
  v->clear();
  neoParseTree(tree, v);
  for (vector<int>::iterator item = v->begin(); item != v->end(); item++) {
    cout << (*item) << endl;
  }

  delete tree;
  delete t1_l;
  delete t1_r;
  delete t2_l;
  delete t2_r;
  delete t3_l;
  delete t3_r;
  delete v;
}
/**
 *
 * 后序遍历并删除tree
 */
template <typename T>
void neoParseAndDeleteTree(Node<T>* tree, vector<T>* v) {
  if (v == NULL || tree == NULL) return;
  neoParseTree(tree->left, v);
  neoParseTree(tree->right, v);
  v->push_back(tree->data);
  delete tree;
}

void testCreate() {
  vector<int>* middle = new vector<int>;
  middle->push_back(4);
  middle->push_back(2);
  middle->push_back(5);
  middle->push_back(1);
  middle->push_back(6);
  middle->push_back(3);
  middle->push_back(7);

  vector<int>* pre = new vector<int>;
  pre->push_back(1);
  pre->push_back(2);
  pre->push_back(4);
  pre->push_back(5);
  pre->push_back(3);
  pre->push_back(6);
  pre->push_back(7);
  //需要在调用createTree时创建root Node指针,这样 在创建完tree之后才能遍历输出
  Node<int>* tree = new Node<int>;
  createTree(tree, middle, pre);
  cout << "end" << endl;
  //使用后序遍历 输出tree
  vector<int>* v = new vector<int>;
  neoParseAndDeleteTree(tree, v);
  for (vector<int>::iterator item = v->begin(); item != v->end(); item++) {
    cout << (*item) << endl;
  }
  delete v;
}