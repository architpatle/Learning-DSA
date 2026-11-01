#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                q.push(i);
            }

            m[s[i]]++;

            while (q.size() > 0 && m[s[q.front()]] > 1)
            {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};

void runTest(string s)
{
    Solution sol;

    int result = sol.firstUniqChar(s);

    cout << "Input: \"" << s << "\"";
    cout << "\nOutput: " << result;

    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest("leetcode");
    // Expected: 0
    // 'l' is the first non-repeating character

    // Test 2
    runTest("loveleetcode");
    // Expected: 2
    // 'v' is the first non-repeating character

    // Test 3
    runTest("aabb");
    // Expected: -1
    // No unique character

    // Test 4
    runTest("a");
    // Expected: 0

    // Test 5
    runTest("abcabc");
    // Expected: -1

    // Test 6
    runTest("aabbc");
    // Expected: 4

    // Test 7
    runTest("z");
    // Expected: 0

    // Test 8
    runTest("aabbccdde");
    // Expected: 8

    // Test 9
    runTest("abcde");
    // Expected: 0

    // Test 10
    runTest("aabbccddeeffg");
    // Expected: 12

    return 0;
}