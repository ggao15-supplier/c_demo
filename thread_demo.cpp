#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#define NUM 6
using namespace std;

void handler(void* arg) {
  int second = *((int*)arg);
  std::this_thread::sleep_for(std::chrono::seconds(second));
  cout << "thread11:" << this_thread::get_id << ";" << second << endl;
}
int main() {
  pthread_t tids[NUM];
  for (int i = 0; i < NUM; i++) {
    thread mythread = thread(handler, &i);
    mythread.join();
  }

  return 0;
}