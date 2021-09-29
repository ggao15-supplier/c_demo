#include <math.h>

#include <iostream>

#include "tree.h"
using namespace std;

template <class T>
int calHeight(AVLNode<T>* tree) {
  if (tree == NULL) {
    return 0;
  }
  return max<int>(calHeight(tree->left), calHeight(tree->right)) + 1;
}

template <class T>
int treeGetBalanceFactor(AVLNode<T>* tree) {
  if (tree == NULL) return 0;
  return tree->left->height - tree->right->height;
}
void testCreateAVL() {}