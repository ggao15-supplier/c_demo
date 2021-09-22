#include <functional>
#include <future>
#include <iostream>
#include <thread>
using namespace std;

string helloFunction(string s) {
  cout << "start: " << s << ";thread:" << this_thread::get_id() << endl;
  this_thread::sleep_for(chrono::seconds(1));
  return "Hello from " + s + ";";
}

void testAsync() {
  cout << "main: " << this_thread::get_id() << endl;
  future<string> result = async(helloFunction, "function");
  while (result.wait_for(chrono::milliseconds(100)) != future_status::ready) {
    cout << ".." << endl;
  }
  cout << result.get() << endl;
}

void promiseFunction(future<int> &fut) {
  cout << "value:" << fut.get() << endl;
}

void testPromise() {
  promise<int> prom;
  future<int> fut = prom.get_future();
  thread t1 = thread(promiseFunction, ref(fut));
  prom.set_value(200);
  t1.join();
}

int countdown(int from, int to) {
  for (int i = from; i != to; i--) {
    cout << "step is " << i << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }

  return from - to;
}

void testTask() {
  packaged_task<int(int, int)> tsk(countdown);
  future<int> fut = tsk.get_future();
  thread t2(move(tsk), 10, 0);
  int result = fut.get();
  cout << "result is " << result << endl;
  t2.join();
}
int main() {
  testAsync();
  testPromise();
  testTask();

  return 0;
}