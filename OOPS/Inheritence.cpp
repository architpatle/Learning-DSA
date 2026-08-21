#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

};

class Student: public Person{
    public:
    int rollNo;
    
    Student(string name, int age, int rollNo): Person(name,age){
        this->rollNo = rollNo;
    }
    void getInfo(){
        cout<<"Name: "<<name <<endl;
        cout<<"Age: "<<age <<endl;
        cout<<"Roll No.: "<<rollNo <<endl;
    }
};

int main(){

    Student s1("Archit", 21, 43);
   
    s1.getInfo();

    return 0;
}