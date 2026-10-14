#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> st;

        for (int i = 0; i < str.size(); i++)
        {

            // opening brackets
            if (str[i] == '{' || str[i] == '[' || str[i] == '(')
            {
                st.push(str[i]);
            }
            else
            {
                // closing brackets
                if (st.size() == 0)
                {
                    return false;
                }

                if ((st.top() == '{' && (str[i] == '}')) ||
                    (st.top() == '[' && (str[i] == ']')) ||
                    (st.top() == '(' && (str[i] == ')')))
                {
                    st.pop();
                } else{
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};

int main()
{
    Solution solution;

    // =====================================================
    // TEST CASE 1
    //
    // Input:
    // ()
    //
    // Expected:
    // true
    // =====================================================

    string str1 = "()";

    cout << "Test Case 1:" << endl;
    cout << "Input:  " << str1 << endl;
    cout << "Result: "
         << (solution.isValid(str1) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 2
    //
    // Input:
    // ()[]{}
    //
    // Expected:
    // true
    // =====================================================

    string str2 = "()[]{}";

    cout << "\nTest Case 2:" << endl;
    cout << "Input:  " << str2 << endl;
    cout << "Result: "
         << (solution.isValid(str2) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 3
    //
    // Input:
    // (]
    //
    // Expected:
    // false
    // =====================================================

    string str3 = "(]";

    cout << "\nTest Case 3:" << endl;
    cout << "Input:  " << str3 << endl;
    cout << "Result: "
         << (solution.isValid(str3) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 4
    //
    // Input:
    // ([)]
    //
    // Expected:
    // false
    // =====================================================

    string str4 = "([)]";

    cout << "\nTest Case 4:" << endl;
    cout << "Input:  " << str4 << endl;
    cout << "Result: "
         << (solution.isValid(str4) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 5
    //
    // Input:
    // {[]}
    //
    // Expected:
    // true
    // =====================================================

    string str5 = "{[]}";

    cout << "\nTest Case 5:" << endl;
    cout << "Input:  " << str5 << endl;
    cout << "Result: "
         << (solution.isValid(str5) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 6
    //
    // Input:
    // (
    //
    // Expected:
    // false
    // =====================================================

    string str6 = "(";

    cout << "\nTest Case 6:" << endl;
    cout << "Input:  " << str6 << endl;
    cout << "Result: "
         << (solution.isValid(str6) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 7
    //
    // Input:
    // )
    //
    // Expected:
    // false
    // =====================================================

    string str7 = ")";

    cout << "\nTest Case 7:" << endl;
    cout << "Input:  " << str7 << endl;
    cout << "Result: "
         << (solution.isValid(str7) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 8
    //
    // Input:
    // ""
    //
    // Expected:
    // true
    // =====================================================

    string str8 = "";

    cout << "\nTest Case 8:" << endl;
    cout << "Input:  \"\"" << endl;
    cout << "Result: "
         << (solution.isValid(str8) ? "true" : "false")
         << endl;

    // =====================================================
    // TEST CASE 9
    //
    // Input:
    // {[()]}
    //
    // Expected:
    // true
    // =====================================================

    string str9 = "{[()]}";

    cout << "\nTest Case 9:" << endl;
    cout << "Input:  " << str9 << endl;
    cout << "Result: "
         << (solution.isValid(str9) ? "true" : "false")
         << endl;

    return 0;
}