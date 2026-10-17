#include <iostream>
#include <stack>

using namespace std;

// ------------- APPROACH 1 ---------------

// class MinStack
// {
//     stack<pair<int, int>> st;

// public:
//     MinStack()
//     {
//         // Initialize your stack here
//     }

//     void push(int value)
//     {
//         int minVal = min(value, minVal);

//         if (st.empty())
//         {
//             st.push({value, value});
//         }
//         else
//         {
//             st.push({value, minVal});
//         }
//     }

//     void pop()
//     {
//         // Write your solution here
//         st.pop();
//     }

//     int top()
//     {
//         // Write your solution here
//         return st.top().first;
//     }

//     int getMin()
//     {
//         // Write your solution here
//         return st.top().second;
//     }
// };

// ------------- APPROACH 2 -------------------

class MinStack
{
    stack<long long int> st;
    long long int minVal;

public:
    MinStack()
    {
        // Initialize your stack here
    }

    void push(int value)
    {
        if (st.empty())
        {
            st.push(value);
            minVal = value;
        }
        else if (value < minVal)
        {
            st.push((long long)2 * value - minVal);
            minVal = value;
        }
        else
        {
            st.push(value);
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = 2 * minVal - st.top();
        }

        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
    // ==========================================
    // Test Case 1
    // ==========================================

    cout << "Test Case 1" << endl;

    MinStack st1;

    st1.push(-2);
    st1.push(0);
    st1.push(-3);

    cout << "Minimum: " << st1.getMin() << endl;
    // Expected: -3

    st1.pop();

    cout << "Top: " << st1.top() << endl;
    // Expected: 0

    cout << "Minimum: " << st1.getMin() << endl;
    // Expected: -2

    // ==========================================
    // Test Case 2
    // ==========================================

    cout << "\nTest Case 2" << endl;

    MinStack st2;

    st2.push(5);
    st2.push(3);
    st2.push(7);
    st2.push(2);
    st2.push(4);

    cout << "Top: " << st2.top() << endl;
    // Expected: 4

    cout << "Minimum: " << st2.getMin() << endl;
    // Expected: 2

    st2.pop();

    cout << "Top after pop: " << st2.top() << endl;
    // Expected: 2

    cout << "Minimum after pop: " << st2.getMin() << endl;
    // Expected: 2

    st2.pop();

    cout << "Top after pop: " << st2.top() << endl;
    // Expected: 7

    cout << "Minimum after pop: " << st2.getMin() << endl;
    // Expected: 3

    // ==========================================
    // Test Case 3
    // Testing duplicate minimum values
    // ==========================================

    cout << "\nTest Case 3" << endl;

    MinStack st3;

    st3.push(2);
    st3.push(1);
    st3.push(1);
    st3.push(3);

    cout << "Minimum: " << st3.getMin() << endl;
    // 1

    st3.pop();

    cout << "Minimum after pop: " << st3.getMin() << endl;
    // 1

    st3.pop();

    cout << "Minimum after removing one duplicate min: "
         << st3.getMin() << endl;
    // 1

    st3.pop();

    cout << "Minimum after removing both min values: "
         << st3.getMin() << endl;
    // 2

    // ==========================================
    // Test Case 4
    // Negative numbers
    // ==========================================

    cout << "\nTest Case 4" << endl;

    MinStack st4;

    st4.push(-5);
    st4.push(-10);
    st4.push(-3);
    st4.push(-20);

    cout << "Top: " << st4.top() << endl;
    // Expected: -20

    cout << "Minimum: " << st4.getMin() << endl;
    // Expected: -20

    st4.pop();

    cout << "Top after pop: " << st4.top() << endl;
    // Expected: -3

    cout << "Minimum after pop: " << st4.getMin() << endl;
    // Expected: -10

    return 0;
}