#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue()
    {
        // Write your constructor here
    }

    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        int ans = st1.top();
        st1.pop();

        return ans;
    }

    int peek()
    {
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

// Test Case 1
void runTest1()
{

    cout << "Test Case 1" << endl;

    MyQueue *obj = new MyQueue();

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "push(2)" << endl;
    obj->push(2);

    cout << "peek() = "
         << obj->peek()
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

// Test Case 2
void runTest2()
{

    cout << "Test Case 2" << endl;

    MyQueue *obj = new MyQueue();

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "push(2)" << endl;
    obj->push(2);

    cout << "push(3)" << endl;
    obj->push(3);

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
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

// Test Case 3
void runTest3()
{

    cout << "Test Case 3" << endl;

    MyQueue *obj = new MyQueue();

    cout << "empty() = "
         << (obj->empty() ? "true" : "false")
         << endl;

    cout << "push(5)" << endl;
    obj->push(5);

    cout << "peek() = "
         << obj->peek()
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

// Test Case 4
void runTest4()
{

    cout << "Test Case 4" << endl;

    MyQueue *obj = new MyQueue();

    cout << "push(7)" << endl;
    obj->push(7);

    cout << "push(8)" << endl;
    obj->push(8);

    cout << "push(9)" << endl;
    obj->push(9);

    cout << "push(1)" << endl;
    obj->push(1);

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
         << endl;

    delete obj;

    cout << "-----------------------------" << endl;
}

// Test Case 5
void runTest5()
{

    cout << "Test Case 5" << endl;

    MyQueue *obj = new MyQueue();

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

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
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

// Test Case 6
void runTest6()
{

    cout << "Test Case 6" << endl;

    MyQueue *obj = new MyQueue();

    cout << "push(4)" << endl;
    obj->push(4);

    cout << "push(5)" << endl;
    obj->push(5);

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "push(6)" << endl;
    obj->push(6);

    cout << "push(7)" << endl;
    obj->push(7);

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
         << endl;

    cout << "pop() = "
         << obj->pop()
         << endl;

    cout << "peek() = "
         << obj->peek()
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

    runTest6();

    return 0;
}