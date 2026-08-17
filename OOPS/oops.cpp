#include <iostream>
#include <string>
using namespace std;

// Creating a class
class Teacher
{
private:
    double salary;

public: // access modifier

    // constructor (Non parametrized)
    Teacher(){
        cout<<"Created a constructor.\n";
    }

    // constructor (parametrized)
    Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }


    // Data Members (properties/attributes)
    string name;
    string dept;
    string subject;

    // Member Functions (Methods)

    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // setter
    void setSalary(double s)
    {
        salary = s;
    }

    // getter
    double getSalary()
    {
        return salary;
    }

    // getter
    void getValues(){
        cout<<"Name: "<<name<<endl;
        cout<<"Dept: "<<dept<<endl;
        cout<<"Sub: "<<subject<<endl;
        cout<<"Sal: "<<salary;
    }
};

int main()
{
    // creating an object
    
    Teacher t1("Archit", "CSE", "OOPS", 45000);

    t1.getValues();

    return 0;
}