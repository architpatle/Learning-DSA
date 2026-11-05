#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int totalScore = 0;
        stack<int> st;

        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "+")
            {
                int x = st.top();
                st.pop();

                int y = st.top();
                st.pop();

                int z = x + y;

                st.push(y);
                st.push(x);
                st.push(z);
            }
            else if (ops[i] == "D")
            {
                st.push(2 * st.top());
            }
            else if (ops[i] == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(ops[i]));
            }
        }

        while(!st.empty()){
            totalScore += st.top();
            st.pop();
        }

        return totalScore;
    }
};

void runTest(vector<string> ops)
{
    Solution sol;

    int result = sol.calPoints(ops);

    cout << "Operations: [";

    for (int i = 0; i < ops.size(); i++)
    {
        cout << "\"" << ops[i] << "\"";

        if (i != ops.size() - 1)
            cout << ", ";
    }

    cout << "]";

    cout << "\nOutput: " << result;
    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({"5", "2", "C", "D", "+"});
    // Expected: 30

    // Test 2
    runTest({"5", "-2", "4", "C", "D", "9", "+", "+"});
    // Expected: 27

    // Test 3
    runTest({"1", "C"});
    // Expected: 0

    // Test 4
    runTest({"10", "20", "+"});
    // Expected: 60

    // Test 5
    runTest({"5", "D", "D"});
    // Expected: 35

    // Test 6
    runTest({"1", "2", "3", "C"});
    // Expected: 3

    // Test 7
    runTest({"-5", "-10", "+"});
    // Expected: -30

    // Test 8
    runTest({"10", "20", "30", "+", "D", "C"});
    // Expected: 120

    // Test 9
    runTest({"1", "2", "+", "C", "D"});
    // Expected: 6

    // Test 10
    runTest({"100", "-50", "D", "+", "C", "10"});
    // Expected: 60

    return 0;
}