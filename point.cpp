#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;
typedef struct Book {
    string title;
    string author;
    string subject;
    double price;
}Book;

void printBook (Book book, Book *b) {
    cout << "title:" << book.title << ";subject:" << book.subject << endl;
    cout << "title:" << b->title << ";subject:" << b->subject << ";author:" << b->author << endl;
}
int main2() {
    int *ptr = NULL;
    int intes[] = {1, 3, 5, 5, 6};
    ptr = intes;
    for (int i = 0; i < 5; i++) {
        cout << * (ptr++) << endl;
    }
    time_t now = time (0);
    cout << "time:" << ctime (&now) << endl;
    tm *gmtm = gmtime (&now);
    cout << "UTC:" << asctime (gmtm) << endl;

    tm *local_time = localtime (&now);
    cout << "year:" << 1900 + local_time->tm_year << endl;
    cout << "month:" << 1 + local_time->tm_mon << endl;
    cout << "day_year:" << local_time->tm_yday << endl;
    cout << "day_month:" << local_time->tm_mday << endl;
    cout << "hour:" << local_time->tm_hour << endl;
    cout << "minute:" << local_time->tm_min << endl;
    cout << "second:" << local_time->tm_sec << endl;
    string in;
    cin >> in;
    cout << in << endl;
    cerr << "Error" << endl;
    clog << "1111" << endl;
    Book b;
    b.author = "111";
    b.title = "222";
    b.subject = "4444";
    printBook (b, &b);
    return 0;
}
