#include <iostream>
using namespace std;

int main()
{

    int x = 10;
    int *ptr = &x;

    cout << x << endl;
    cout << &x << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << *&x << endl;

    cout << "Practice: Write code that changes x from 10 → 50 using only p. =>" << endl;

    int a = 10;
    int *p = &a;

    cout << "x: " << a << endl;

    // *p = 50;
    *&a = 50;

    cout << "x: " << a << endl;

    // Reference
    cout << "References : " << endl;

    int r = 100;
    int &ref = r;

    cout << r << endl;
    cout << &r << endl;
    cout << ref << endl;
    cout << &ref << endl;

    ref = 1000;

    cout << r << endl;

    // const + Pointers

    cout << "const + Pointers: " << endl;

    int b = 60;
    const int *pointer = &b; // pointer to const

    cout << b << endl;

    b = 90;
    pointer = &x;
    // *pointer = 90; not possible

    cout << b << endl;
    cout << *pointer << endl;


    int *const point = &b;

    cout << b << endl;

    *point = 190;
    // point = &x; not possible

    cout << b << endl;


    int *z = nullptr;

    cout<<*z;
}