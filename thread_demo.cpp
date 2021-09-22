
#include <atomic>
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#define NUM 6
using namespace std;

int total = 100;
mutex mu;
void thread1() {
  for (int i = 0; i < NUM; i++) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread 1 is working..." << endl;
  }
}
void thread2() {
  for (int i = 0; i < NUM; i++) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread 2 is working..." << endl;
  }
}

void threadHandler(string name) {
  for (int i = 0; i < NUM; i++) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread: " << name << " is working..." << endl;
  }
}

void mutexThread1() {
  while (total > 0) {
    mu.lock();
    cout << "thread1,total:" << total << endl;
    total--;
    this_thread::sleep_for(chrono::milliseconds(500));
    mu.unlock();
  }
}

void mutexThread2() {
  while (total > 0) {
    mu.lock();
    cout << "thread2,total:" << total << endl;
    total--;
    this_thread::sleep_for(chrono::milliseconds(300));
    mu.unlock();
  }
}

void jonThread() {
  thread t1(thread1);
  thread t2(thread2);
  t1.join();
  t2.join();
}

void detachThread() {
  cout << "********detach thread*******" << endl;
  thread t1(threadHandler, "11");
  thread t2(threadHandler, "22");
  t1.detach();
  t2.detach();
  // main thread  need to do some also
  for (int i = 0; i < NUM; i++) {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "main thread is work..." << endl;
  }
}

void mutexDetachThread() {
  thread t1(mutexThread1);
  thread t2(mutexThread2);
  t1.detach();
  t2.detach();
  system("pause");
}
int main() {
  // jonThread();
  detachThread();
  // mutexDetachThread();
  return 0;
}