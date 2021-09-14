#include "global.h"

using namespace std;

extern int version;

enum City {
    Shanghai,
    Beijing = 20,
    Qingdao
} city;

string selectCity (City c) {
    if (c == Shanghai) {
        return "Shanghai";
    } else if (c == Beijing) {
        return "Beijing";
    } else {
        return "Qingdao";
    }
}
auto getValues() {
    auto result = 0;
    int type = 10;
    switch (type) {
    case 10:
        result = 1.7f;
        break;
    default:
        result = 'a';
        break;
    }

    return result;
}
void swap (int *x, int *y) {
    cout << "x:" << x << ";y:" << y << endl;
    cout << "*x:" << *x << ";*y:" << *y << endl;
    int temp = *x;
    *x = *y;
    *y = temp;

}
void swap (int &x, int &y, int c) {
    cout << "x:" << x << ";y:" << y << endl;
    cout << "&x:" << &x << ";&y:" << &y << endl;
    int temp = x;
    x = y;
    y = temp;
}

int main1() {
    const int WIDTH = 10;

    int version = 60;//not work
    city = Shanghai;
    cout << "city:" << city << ";" << version << endl;
    version = 333;
    cout << version << endl;
    string str = selectCity (city);
    cout << str << endl;
    cout << LENGTH*WIDTH << endl;
    auto result = getValues();
    cout << result << endl;
    cout << "-------------------------------" << endl;

    int x = 100;
    int y = 200;
    cout << "before:x:" << x << "y:" << y << endl;
    swap (&x, &y);
    cout << "after:x:" << x << "y:" << y << endl;

    int a = 900;
    int b = 1000;

    cout << "before:a:" << a << "b:" << b << endl;
    swap (a, b, 10);
    cout << "after:a:" << a << ";b:" << b << endl;
    abs (1.0);
    floor (1.01);
    srand ( (unsigned) time (NULL) );
    cout << rand() << endl;
    return 0;
}
