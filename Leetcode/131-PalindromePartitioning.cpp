#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string part)
{

    string partRev = part;

    reverse(partRev.begin(), partRev.end());

    return part == partRev;
}

void getAllPartitions(string s, vector<vector<string>> &ans, vector<string> &partitions)
{
    if(s.size() == 0){
        ans.push_back(partitions);

        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);

        if (isPalindrome(part))
        {
            partitions.push_back(part);

            getAllPartitions(s.substr(i + 1), ans, partitions);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllPartitions(s, ans, partitions);

    return ans;
}

int main()
{
    string s = "aaba";

    partition(s);

    vector<vector<string>> ans = partition(s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}