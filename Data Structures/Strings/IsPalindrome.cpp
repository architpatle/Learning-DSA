#include <iostream>
#include <vector>
using namespace std;

// isPalindorme Problem

bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isPalindrome(string str)
{
    int start = 0, end = str.length() - 1;

    while (start < end)
    {
        if (!isAlphaNumeric(str[start]))
        {
            start++;
            continue;
        }

        if (!isAlphaNumeric(str[end]))
        {
            end--;
            continue;
        }

        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }

        start++;
        end--;
    }
    return true;
}

bool isPalindromeNum(int x)
{
    if (x < 0)
    {
        return false;
    }
    vector<int> nums;

    while (x > 0)
    {
        nums.push_back(x % 10);
        x = x / 10;
    }

    // for(int val: nums){
    //     cout<<val<<" ";
    // }
    int start = 0, end = nums.size() - 1;

    while (start < end)
    {
        if (nums[start] != nums[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

bool isAlphaNumericPractice(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        return true;

    return false;
}

bool isPalindromePractice(string str)
{
    int start = 0, end = str.length() - 1;

    while (start < end)
    {
        if (!isAlphaNumericPractice(str[start]))
        {
            start++;
            continue;
        }
        if (!isAlphaNumericPractice(str[end]))
        {
            end--;
            continue;
        }

        if (tolower(str[start]) != tolower(str[end]))
            return false;

      

        start++;
        end--;
    }
      return true;
}

int main()
{
    string str = "d";

    cout << isPalindromePractice(str);

    return 0;
}
