#include <iostream>
#include <string>
#include <vector>

#include "tree.h"
template <typename T>
Node<T>* createTree(vector<T>* middle, vector<T>* pre, int currentIndex,
                    int preIndex) {
  Node<T>* tree = new Node<T>;
  T value = pre->pop_back();
  tree->data = value;
  int index = middle - while (!pre->empty()){

                       } { /* code */
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
void testCreate() {}