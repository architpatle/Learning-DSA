#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int minOperations(vector<string> &logs)
{
    stack<string> st;
    int count = 0;

    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "../")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (logs[i] == "./")
        {
            continue;
        }
        else
        {
            st.push(logs[i]);
        }
    }

    while (!st.empty())
    {
        count++;
        st.pop();
    }

    return count;
}

int main()
{
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};

    cout << "Min Operations: " << minOperations(logs);

    return 0;
}