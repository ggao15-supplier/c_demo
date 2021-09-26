#include <iostream>
#include <string>

using namespace std;
class Person {
private:
    string sex;
public:
    void setSex (string sex) {
        this->sex = sex;
    }
    string getSex() {
        return this->sex;
    }
};
class Student : private Person {

private:
    string name;
    int age;
public:
    static int SV;

    static int getV() {
        return Student::SV;
    }
    Student (string name, int age) : name (name), age (age) {

        cout << "constructor" << endl;
    }
    Student (string name);
    ~Student() {
        cout << "deleted" << endl;
    }
    Student (const Student &obj) {
        cout << "copy" << endl;
        age = obj.age;
        name = obj.name + "::copy";
    }
    void setName (string name) {
        this->name = name;
    }
    void setAge (int age) {
        this->age = age;
    }
    string getName() {
        setSex ("male");
        return this->name;
    }
    int getAge() {
        return this->age;
    }
    string toString();
};
int Student::SV = 222;
string Student::toString() {

    return "name:" + this->name + ";age:";
}
Student::Student (string n) : name (n) {
}

void printe (Student obj) {
    cout << obj.toString() << endl;
}
int main3() {

    Student student = Student ("sss", 22);
    student.setAge (123);
    student.setName ("sdsd");

    Student *s = new Student ("ss", 222);

    cout << "name:" << student.getName() << ";age:" << student.getAge() << endl;
    cout << "toString:" << student.toString() << endl;
    printe (student);

    cout << "V:" << Student::getV() << endl;

    delete s;
    return 0;
}
