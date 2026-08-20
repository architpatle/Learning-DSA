#include <iostream>
using namespace std;

class Student
{

public:
    string name;
    double *cgpaPtr;

    // Constructor (Parametrized)
    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double; // new memory of type double is allocated to cgpaPtr
        *cgpaPtr = cgpa;
    }

    // Constructor (Copy)
    Student(Student &obj)
    {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    // Destructor
    ~Student(){
        cout<<"Destructor is called!";
        delete cgpaPtr;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};

int main()
{
    Student s1("Archit", 8.9);
    // Using copy constructor to copy s1 in s2
    Student s2(s1);

    s1.getInfo();
    cout << endl;

    *(s2.cgpaPtr) = 9.2;
    s2.getInfo();

    cout << endl;
    s1.getInfo();


    return 0;
}