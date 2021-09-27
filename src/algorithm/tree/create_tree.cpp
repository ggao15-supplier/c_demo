#include <iostream>
#include <string>
#include <vector>

#include "tree.h"

template <typename T>
int index(vector<T>* list, T value) {
  for (int i = 0; i < list->size(); i++) {
    if ((*list)[i] == value) return i;
  }
  return -1;
}
//添加一个 判断中序的函数
template <typename T>
void createTree(Node<T>* tree, vector<T>* middle, vector<T>* pre,
                int preIndex) {
  for (int i = 0; i < pre->size(); i++) {
    T data = (*pre)[i];
    if (preIndex == -1) {
      tree = new Node<T>;
      tree->data = data;
    } else {
      int middleIndex = index(middle, data);
      if (middleIndex < preIndex) {
        if (tree->left == NULL) {
          tree->left = new Node<T>;
          tree->left->data = data;
        } else {
          createTree(tree->left, middle, pre, middleIndex);
        }

      } else {
        if (tree->right == NULL) {
          tree->right = createTree(middle, pre, middleIndex);
        } else {
          createTree(tree->right, middle, pre, middleIndex);
        }
      }
    }
  }

  return tree;
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

  Node<int>* tree = createTree(middle, pre, -1);
  vector<int>* v = new vector<int>;
  neoParseTree(tree, v);
  for (vector<int>::iterator item = v->begin(); item != v->end(); item++) {
    cout << (*item) << endl;
  }
}