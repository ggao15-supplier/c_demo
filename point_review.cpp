#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string name;
  int age;
};
typedef Student* P_Student;

class Class {
 private:
  vector<P_Student>* students;
  string className;

 public:
  Class(string name);
  ~Class() {
    int size = students->size();
    for (int i = 0; i < size; i++) {
      delete students->at(i);
    }
    delete students;
  }
  vector<P_Student>* getStudents() { return students; }
  string getClassName() { return className; }
};
typedef Class* P_Class;

class School {
 private:
  vector<P_Class>* classes;

 public:
  School();
  ~School() {
    int size = classes->size();
    for (int i = 0; i < size; i++) {
      delete ((*classes)[i]);
    }

    delete classes;
  }
  vector<P_Class>* getClasses() { return classes; }
};
typedef School* P_School;

P_Student initStudent(string name, int age) {
  P_Student p_s1 = new Student;
  p_s1->name = name;
  p_s1->age = age;
  return p_s1;
}
vector<P_Student>* initData() {
  vector<P_Student> students;
  vector<P_Student>* p_students = new vector<P_Student>;

  p_students->push_back(initStudent("aaa", 10));
  p_students->push_back(initStudent("bbb", 11));
  p_students->push_back(initStudent("ccc", 12));

  return p_students;
}
void printStudents(vector<P_Student>* p_datas) {
  cout << "***********printStudents vector struct***************" << endl;
  if (p_datas != NULL) {
    cout << "***********(*p_datas)[i]***************" << endl;
    int size = p_datas->size();
    for (int i = 0; i < size; i++) {
      cout << "name:" << (*p_datas)[i]->name << ";age:" << (*p_datas)[i]->age
           << endl;
    }
    cout << "***********p_datas->at(i)***************" << endl;
    for (int i = 0; i < size; i++) {
      cout << "name:" << p_datas->at(i)->name << ";age" << p_datas->at(i)->age
           << endl;
    }
    cout << "***********iterator/((P_Student)*it)***************" << endl;
    for (vector<P_Student>::iterator it = p_datas->begin();
         it != p_datas->end(); it++) {
      cout << "name:" << ((P_Student)*it)->name << ((P_Student)*it)->age
           << endl;
    }
  }
}

P_Class initClass(string name) {
  P_Class pClass = new Class(name);
  return pClass;
}

Class::Class(string name) : className(name) { students = initData(); }

School::School() {
  classes = new vector<P_Class>;
  classes->push_back(initClass("qust"));
  classes->push_back(initClass("wbs"));
  classes->push_back(initClass("cctv"));
}

int main() {
  P_School school = new School;
  vector<P_Class>* classes = school->getClasses();
  for (vector<P_Class>::iterator it = classes->begin(); it != classes->end();
       it++) {
    P_Class c = ((P_Class)*it);
    cout << "class name:" << c->getClassName() << endl;
    printStudents(((P_Class)*it)->getStudents());
  }
  return 0;
}
