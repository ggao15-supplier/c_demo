
#include <string>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* left;
  Node<T>* right;
};
void testParse();
void testCreate();