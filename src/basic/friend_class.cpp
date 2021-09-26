#include <iostream>
#include <string>

using namespace std;

class TV {
 private:
  int number = 0;
  bool isOn = false;

 public:
  friend class Remoter;
  void open() { isOn = true; }
  void close() { isOn = false; }
  void switchChannel(int number) { this->number = number; }
  void show() {
    cout << "power:" << (this->isOn ? "ON" : "OFF")
         << ";number:" << this->number << endl;
  }
};

class Remoter {
 public:
  void switchChannel(TV *tv, int number);
  void power(TV *tv);
};

void Remoter::switchChannel(TV *tv, int number) {
  if (tv->number != number) tv->switchChannel(number);
}
void Remoter::power(TV *tv) {
  if (tv->isOn) {
    tv->close();
  } else {
    tv->open();
  }
}
int main() {
  TV *tv = new TV;
  Remoter *remoter = new Remoter;
  remoter->power(tv);

  remoter->switchChannel(tv, 20);
  tv->show();
  return 0;
}