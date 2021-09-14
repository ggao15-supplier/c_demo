
#include <unistd.h>

#include <csignal>
#include <iostream>
using namespace std;
void singalHanlder(int singalNumber) {
  cout << "Interrupt singal:" << singalNumber << endl;
  exit(singalNumber);
}

int main222() {
  signal(SIGINT, singalHanlder);

  int i = 0;
  while (++i) {
    cout << "Going to sleep..." << i << endl;
    if (i == 3) {
      raise(SIGINT);
    }
    sleep(1);
  }

  return 0;
}