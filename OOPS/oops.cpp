#include <iostream>
#include <string>
using namespace std;

// Creating a class
class Teacher
{
private:
    double salary;

public: // access modifier
        // Data Members (properties/attributes)
    string name;
    string dept;
    string subject;

    // constructor (Non parametrized)
    Teacher()
    {
        cout << "Created a constructor.\n";
    }

    // constructor (parametrized)
    Teacher(string name, string dept, string subject, double salary)
    {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // copy constructor
    Teacher(Teacher &obj)
    {
        cout << "Custom copy constructor:...";
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

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
    void getValues()
    {
        cout << "Name: " << name << endl;
        cout << "Dept: " << dept << endl;
        cout << "Sub: " << subject << endl;
        cout << "Sal: " << salary;
    }
};

int main()
{
    // creating an object

    Teacher t1("Archit", "CSE", "OOPS", 45000);

    t1.getValues();
    cout << endl;

    Teacher t2(t1);

    cout << endl;

    t2.getValues();

    return 0;
}