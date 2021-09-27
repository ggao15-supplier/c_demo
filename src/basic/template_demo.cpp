#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T Max(T a, T b) {
  return a > b ? a : b;
}

template <class T>
class Stack {
 private:
  vector<T> elems;

 public:
  void push(T e) { elems.push_back(e); }

  T pop() {
    if (elems.empty()) {
      throw out_of_range("empty stack");
    }
    T e = elems.back();
    elems.pop_back();
    return e;
  }
};

int main() {
  int a = 10;
  int b = 20;
  cout << Max(a, b) << endl;
  double d1 = 20, d2 = 34;
  cout << Max(d1, d2) << endl;
  Stack<int> *s = new Stack<int>();
  try {
    s->push(1);
    s->push(2);
    s->pop();
    cout << s->pop() << endl;
    s->pop();
  } catch (exception const &ex) {
    cerr << ex.what() << endl;
  }
  Stack<string *> *names = new Stack<string *>();

  string *n1 = new string;
  n1->append("aaa");
  names->push(n1);
  string *n2 = new string;
  n2->append("bbb");
  names->push(n2);
  string *n3 = new string;
  n3->append("ccc");
  names->push(n3);

  cout << "name:" << *(names->pop()) << endl;
  delete n1;
  delete n2;
  delete n3;
  delete names;
  delete s;
  return 0;
}
