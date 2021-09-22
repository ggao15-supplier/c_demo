#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main222() {
  vector<string> v1;
  v1.push_back("aaa");
  v1.push_back("bbb");
  v1.push_back("ccc");
  cout << "size:" << v1.size() << ";1:" << v1[0] << endl;
  v1.insert(v1.begin(), 1, "222");
  cout << "size:" << v1.size() << ";1:" << v1[0] << endl;
  v1.erase(v1.begin(), v1.end());  // size 为 0 ,但是还可以根据index取到值
  cout << "size:" << v1.size() << ";1:" << v1[2] << ";isEmpty:" << v1.empty()
       << endl;

  cout << "*************map***************" << endl;

  map<string, string> m1;
  m1["aaa"] = "vv";
  m1["bbb"] = "sss";
  m1["ccc"] = "ddd";
  map<string, string> m2(m1);

  for (map<string, string>::iterator item = m2.begin(); item != m2.end();
       item++) {
    cout << "key:" << item->first << ";value:" << item->second << endl;
  }

  return 0;
}