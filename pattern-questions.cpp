#include <iostream>
using namespace std;

int main()
{
    // ***** Square Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // ***** Problem 2 *****

    // int n;

    // cout << "Enter the number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {

    //     char ch = 'A';

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }

    //     cout << endl;
    // }

    // ***** Problem 3 *****

    // int n;
    // int k = 1;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << k << " ";
    //         k++;
    //     }
    //     cout << endl;
    // }

    // ***** Triangle Pattern *****

    // ***** Problem 1 *****

    int n;

    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i >= j)
            {
                cout << "* ";
            }
        }
        cout<<endl;
    }

    return 0;
}