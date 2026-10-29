#include <iostream>
using namespace std;

// Virtual and Override
class Base
{
public:
    virtual void show()
    {
        cout << "Base" << endl;
    }
};

class Dervied : public Base
{
public:
    void show() override
    {
        cout << "Derived" << endl;
    }
};

// Abstract Class
class Animal
{
public:
    virtual void sound() = 0;
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Bark";
    }
};

// Virtual Destructor
class Parent
{
public:
    Parent()
    {
        cout << "Parent Constructor" << endl;
    }

    virtual ~Parent()
    {
        cout << "Parent Destructor" << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child Constructor" << endl;
    }

    ~Child()
    {
        cout << "Child Destructor" << endl;
    }
};

int main()
{

    // Base *ptr = new Dervied();
    // ptr->show();

    // Dog d;
    // d.sound();

    Parent *ptr = new Child();
    delete ptr;



    return 0;
}