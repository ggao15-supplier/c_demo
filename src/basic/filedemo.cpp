#include <iostream>
#include <string>
#include <fstream>
#include<exception>

using namespace std;
struct MyException : public exception {
    const char* what() const throw() {
        return "MyException";
    }
};
namespace space1 {
void func() {
    cout << "space1" << endl;
}
}
namespace space2 {
void func() {
    cout << "space2" << endl;
}
}
using namespace space1;
int main5() {
    char data[100];
    ofstream outFile;
    outFile.open ("afile.txt");
    cout << "enter your name" << endl;
    cin.getline (data, 100);
    outFile << data << endl;
    outFile.close();
    ifstream inFile;
    inFile.open ("afile.txt");
    inFile >> data;
    cout << data << endl;
    inFile.close();
    func();
    try {
        throw std::invalid_argument ("aaa");
    } catch (exception e) {
        cout << e.what() << endl;
    }


    return 0;
}
