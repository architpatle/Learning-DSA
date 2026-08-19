#include <iostream>
using namespace std;

// creating a class
class Student
{
    double fees;

public:
    // Data Members (Properties/ Attributes)
    string name;
    string dept;
    float cgpa;

    // Member Functions (Methods)
    void setInfo(string name, string dept, float cgpa, double fees)
    {
        this->name = name;
        this->dept = dept;
        this->cgpa = cgpa;
        this->fees = fees;
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Dept: " << dept << endl;
        cout << "cgpa: " << cgpa << endl;
        cout << "Fees: " << fees << endl;

    }
};

int main()
{
    // creating object
    Student s1, s2;

    // s1.name ="Archit";
    // s1.dept = "CSE";
    // s1.cgpa = 8.9;
    s1.setInfo("Archit", "CSE", 8.9, 100000);
    s2.setInfo("Palak", "CSE", 8.3, 105000);

    // cout<<"Name: "<<s1.name<<endl;
    // cout<<"Dept: "<<s1.dept<<endl;
    // cout<<"cgpa: "<<s1.cgpa<<endl;

    s1.getInfo();
    cout << endl;
    s2.getInfo();

    return 0;
}