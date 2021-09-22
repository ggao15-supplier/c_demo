#include <unistd.h>

#include <iostream>
#include <string>

using namespace std;

void onlyFork() {
  cout << "fork process.." << endl;
  pid_t cpid = fork();
  if (cpid < 0) {
    cout << "fork failed" << endl;
  } else if (cpid > 0) {
    cout << "fork from parent proccess,the pid is:" << cpid << endl;
  } else {
    cout << "is child proccess,the pid is:" << cpid << endl;
  }
}

int main() {
  onlyFork();
  return 0;
}