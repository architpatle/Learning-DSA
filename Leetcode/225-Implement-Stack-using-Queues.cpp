#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
        // Write your constructor here
    }

    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int ans = q1.front();
        q1.pop();

        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// Helper function to run operations
void runTest1()
{

    cout << "Test Case 1" << endl;

    MyStack *obj = new MyStack();

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "push(2)" << endl;
    obj->push(2);

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

void runTest2()
{

    cout << "Test Case 2" << endl;

    MyStack *obj = new MyStack();

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "push(2)" << endl;
    obj->push(2);

    cout << "push(3)" << endl;
    obj->push(3);

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

void runTest3()
{

    cout << "Test Case 3" << endl;

    MyStack *obj = new MyStack();

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    cout << "push(5)" << endl;
    obj->push(5);

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

void runTest4()
{

    cout << "Test Case 4" << endl;

    MyStack *obj = new MyStack();

    cout << "push(7)" << endl;
    obj->push(7);

    cout << "push(8)" << endl;
    obj->push(8);

    cout << "push(9)" << endl;
    obj->push(9);

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

void runTest5()
{

    cout << "Test Case 5" << endl;

    MyStack *obj = new MyStack();

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "push(2)" << endl;
    obj->push(2);

    cout << "push(3)" << endl;
    obj->push(3);

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "push(4)" << endl;
    obj->push(4);

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "top() = "
         << obj->top()
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

int main()
{

    runTest1();

    runTest2();

    runTest3();

    runTest4();

    runTest5();

    return 0;
}