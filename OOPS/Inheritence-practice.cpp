#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person
{

public:
    int employeeId;
    double salary;

    Employee(string name, int age, int employeeId, double salary) : Person(name, age)
    {
        this->employeeId = employeeId;
        this->salary = salary;
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "EmployeeId: " << employeeId << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee
{

public:
    string department;

    Manager(string name, int age, int employeeId, double salary, string department) : Employee(name, age, employeeId, salary)
    {
        this->department = department;
    }
    void displayManager()
    {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

int main()
{
    Manager m1("Archit", 22, 101, 50000, "IT");

    m1.displayManager();

    return 0;
}