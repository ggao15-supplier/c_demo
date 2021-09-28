
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* left = NULL;
  Node<T>* right = NULL;
};
void testParse();
void testCreate();