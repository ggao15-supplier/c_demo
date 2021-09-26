#include<iostream>
#include <string>

using namespace std;

class PrintData {

public:
    void print (int i) {
        cout << "int:" << i << endl;
    }
    void print (string data) {
        cout << "string:" << data << endl;
    }

};

class Box {
private:
    int quare;
    int width;
    int height;

public:
    Box (int w, int h) : width (w), height (h) {
        this->quare = this->width * this->height;
    }

    virtual int getQuare() {

        return this->quare;
    }
    int getWidth() {
        return this->width;
    }
    int getHeight() {
        return this->height;
    }
    Box operator+ (const Box &b) {
        Box box = Box ( (this->width + b.width), (this->height + b.height) );
        return box;
    }

    Box operator++ (int) {
        int w = this->width + this->width;
        int h = this->height + this->height;

        return Box (w, h);
    }
    Box operator++ () {
        int w = this->width + this->width;
        int h = this->height + this->height;

        return Box (w, h);
    }

    friend ostream& operator<< (ostream &out, const Box &b) {
        out << "width:" << b.width << ";height:" << b.height << ";quare:" << b.quare ;
        return out;
    }

    ostream& operator<< (ostream &out) {
        out << "width:" << width << ";height:" << height << ";quare:" << quare ;
        return out;
    }
};

class RecBox : public Box {
public:
    RecBox (int w, int h) : Box (w, h) {
    }

    int getQuare() {
        return 111;
    }
};

int main4() {
    Box b1 = Box (10, 20);
    Box b2 = Box (30, 50);
    Box b3 = b1 + b2;

    cout << "b3 width:" << b3.getWidth() << ";height:" << b3.getHeight() << ";quare:" << b3.getQuare() << endl;
    Box b4 = b3++;
    cout << "b4 width:" << b4.getWidth() << ";height:" << b4.getHeight() << ";quare:" << b4.getQuare() << endl;
    Box b5 = ++b4;
    cout << "b5 width:" << b5.getWidth() << ";height:" << b5.getHeight() << ";quare:" << b5.getQuare() << endl;
    cout << b5 << endl;
    b4 << cout << endl;

    Box *rb ;
    RecBox rb1 = RecBox (1, 2);
    rb = &rb1;
    cout << rb->getQuare() << endl;

}
