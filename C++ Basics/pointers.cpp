#include <iostream>
using namespace std;

// Pass by Reference using Pointers
int changeFunPtr(int *ptr)
{
    *(ptr) *= 2;
}

// Pass by Reference using Reference(alias)
int changeFunAlias(int &b){
    b *=2;
}

int main()
{
    int a = 10;
    int *ptr = &a;
    int **parentPtr = &ptr;

    cout << a << endl;
    // cout << &a << endl;
    cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << parentPtr << endl;
    // cout << *(&a) << endl;
    // cout<<  *(ptr) <<endl;
    // cout<<  *(parentPtr) <<endl;
    // cout<<  **(parentPtr) <<endl;

    // cout << a << endl;
    // changeFunPtr(&a);
    // changeFunAlias(a);
    // cout << a;

    ptr +=2;
    cout<<ptr<<endl;
    cout<<&a<<endl;
}