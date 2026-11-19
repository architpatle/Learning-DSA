#include <iostream>
using namespace std;

int minChanges(string s)
{
    int changes = 0;

    for(int i = 0; i<s.size(); i +=2){
        if(s[i] != s[i+1]){
            changes++;
        }
    }

    return changes;
}

int main()
{
    string s = "1001";

    cout << "Min Changes: " << minChanges(s);

    return 0;
}