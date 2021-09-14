#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#define NUM 6
using namespace std;
using namespace this_thread;
using namespace chrono;
class StandThreadHandler {
 private:
  thread* myThread;
  int index;

 public:
  StandThreadHandler(thread mt, int n) : myThread(mt), index(n) {
    cout << "crate" << endl;
  }
  thread* getMyThread() { return myThread; }
  int getIndex() { return index; }
};
void standHanlder(void* arg) {
  StandThreadHandler* item = (StandThreadHandler*)arg;
  sleep_for(seconds(1));
  cout << "standThread" << this_thread::get_id << ";" << item->getIndex()
       << endl;
  item->getMyThread()->detach();
}

void* cHandler(void* arg) {
  int index = *((int*)arg);
  sleep(1);
  cout << "thread:" << index << endl;
  pthread_detach(pthread_self());
  return 0;
}
// some problem , not work
void cThread() {
  void* status;
  pthread_t tids[NUM];
  for (int i = 0; i < NUM; i++) {
    pthread_create(&tids[i], NULL, cHandler, &i);
    pthread_join(tids[i], &status);
  }
}
void standThread() {
  for (int i = 0; i < NUM; i++) {
    thread myThread = thread(standHanlder, (&StandThreadHandler(&myThread, i)));
    myThread.join();
  }
}
int main() {
  cThread();
  standThread();
  return 0;
}