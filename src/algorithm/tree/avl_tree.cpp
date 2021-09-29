#include <math.h>

#include <iostream>
#include <vector>

#include "tree.h"
using namespace std;

template <class T>
int calHeight(AVLNode<T>* tree) {
  if (tree == NULL) {
    return 0;
  }
  int h = max<int>(calHeight(tree->left), calHeight(tree->right)) + 1;
  tree->height = h;
  return h;
}
template <class T>
AVLNode<T>* roateLeft(AVLNode<T>* tree) {
  AVLNode<T>* temp = tree->left;
  tree->left = temp->right;
  temp->right = tree;

  calHeight(temp);

  return temp;
}

template <class T>
AVLNode<T>* roateRight(AVLNode<T>* tree) {
  AVLNode<T>* temp = tree->right;
  tree->right = temp->left;
  temp->left = tree;
  calHeight(temp);

  return temp;
}

template <class T>
int treeGetBalanceFactor(AVLNode<T>* tree) {
  if (tree == NULL) return 0;
  int leftH = 0;
  if (tree->left != NULL) {
    leftH = tree->left->height;
  }
  int rightH = 0;
  if (tree->right != NULL) {
    rightH = tree->right->height;
  }
  return leftH - rightH;
}

template <class T>
AVLNode<T>* balance(AVLNode<T>* tree) {
  int factor = treeGetBalanceFactor(tree);

  if (factor > 1 && treeGetBalanceFactor(tree->left) > 0) {  // LL
    return roateLeft(tree);
  } else if (factor > 1 && treeGetBalanceFactor(tree->left) < 0) {  // LR
    tree->left = roateLeft(tree->left);
    return roateRight(tree);
  } else if (factor < -1 && treeGetBalanceFactor(tree->right) < 0) {  // RR
    return roateRight(tree);
  } else if (factor < -1 && treeGetBalanceFactor(tree->right) > 0) {  // RL
    tree->right = roateRight(tree->right);
    roateLeft(tree);
  } else {
    return tree;
  }
}

template <class T>
void createAVLTree(AVLNode<T>* tree, T data) {
  if (tree->data > data) {
    if (tree->left == NULL) {
      tree->left = new AVLNode<T>;
      tree->left->data = data;
    } else {
      createAVLTree(tree->left, data);
    }
  } else {
    if (tree->right == NULL) {
      tree->right = new AVLNode<T>;
      tree->right->data = data;
    } else {
      createAVLTree(tree->right, data);
    }
  }
}
template <class T>
AVLNode<T>* createAVL(vector<T>* datas) {
  AVLNode<int>* tree;
  for (int i = 0; i < datas->size(); i++) {
    if (i == 0) {
      tree = new AVLNode<int>;
      tree->data = (*datas)[i];
    } else {
      createAVLTree(tree, (*datas)[i]);
    }
  }

  calHeight(tree);
  tree = balance(tree);

  return tree;
}

void testCreateAVL() {
  vector<int> array = {4, 2, 5, 1, 6, 3, 7, 8, 9, 10};
  AVLNode<int>* tree = createAVL(&array);
  cout << "tree:" << tree->data << ":" << tree->height << ";"
       << "left:" << tree->left->data << ":" << tree->left->height << ";"
       << "right:" << tree->right->data << ":" << tree->right->height << ";"
       << endl;
}