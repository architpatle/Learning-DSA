#include <iostream>
using namespace std;

class Student
{
    int *marks;

    Student(int m)
    {
        marks = new int(m);
    }

    Student(const Student &other)
    {
        marks = new int(*other.marks);
    }
};

int main()
{
    // int *p = new int(50);

    // cout << p << endl;
    // cout << *p << endl;

    // delete p;
    // p = nullptr;

    int *ptr = nullptr;

    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}