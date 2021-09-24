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
    cout << "fork from parent proccess,the cpid is:" << cpid
         << " ;the getPid is: " << getpid() << endl;
  } else {
    cout << "is child proccess,the pid is:" << getpid() << endl;
  }
}

int mainF() {
  onlyFork();
  return 0;
}