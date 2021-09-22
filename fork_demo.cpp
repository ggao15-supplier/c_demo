#include <unistd.h>

#include <iostream>
#include <string>

using namespace std;
// https://blog.csdn.net/yx903520/article/details/106359598

// 自动补全功能的配置
void onlyFork() {
  cout << "fork process.." << endl;
  pid_t cpid = fork();
  if (cpid < 0) {
    cout << "fork failed" << endl;
  } else if (cpid > 0) {
    cout << "fork from parent proccess,the cpid is:" << cpid
         << " ;the getPid is: " << getpid() << endl;
  } else {
    cout << "is child proccess,the pid is:" << getpid() << endl;
  }
}

int main() {
  onlyFork();
  return 0;
}