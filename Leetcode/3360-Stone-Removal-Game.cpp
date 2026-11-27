#include <iostream>
using namespace std;

bool canAliceWin(int n)
{
    bool ans = false;
    int stonesToRemove = 10;

    while (stonesToRemove <= n)
    {
        n -= stonesToRemove;

        if (ans)
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
        stonesToRemove--;
    }

    return ans;
}

int main()
{
    int n = 1;

    cout << "Can Alice win: " << canAliceWin(n);

    return 0;
}