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

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {

    //         if (i >= j)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // ***** Problem 2 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for(int i=0; i<n; i++){

    //     for(int j=0; j<=i; j++){
    //         cout<<i+1;
    //     }

    //     cout<<endl;
    // }

    // ***** Problem 3 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;
    // char ch = 'A';

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << ch<<" ";
    //     }
    //     cout << endl;
    //         ch++;

    // }

    // ***** Problem 4 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << j+1;
    //     }
    //     cout << endl;
    // }

    // ***** Reverse Triangle Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j > 0; j--)
    //     {
    //         cout << j;
    //     }

    //     cout << endl;
    // }

    // ***** Floyd's Triangle Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;
    // int k = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << k << " ";
    //         k++;
    //     }

    //     cout << endl;
    // }

    // ***** Problem 2 *****

    // int n;
    // char ch = 'A';

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j > 0; j--)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }

    //     cout << endl;
    // }

    // ***** Inverted Triangle Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int k = 0; k < i; k++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 0; j < n - i; j++)
    //     {

    //         cout << i + 1<< " ";
    //     }

    //     cout << endl;
    // }

    // ***** Pyramid Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j<n-i-1; j++){
    //         cout<<"  ";
    //     }
    //     for(int k = 0; k<=i; k++){
    //         cout<<k+1<<" ";
    //     }
    //     for(int l = i; l>0; l--){
    //         cout<<l<<" ";
    //     }

    //     cout<<endl;
    // }

    // ***** Hollow Diamond Pattern *****

    // ***** Problem 1 *****

    // int n;

    // cout << "Enter a number: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         cout << "  ";
    //     }
    //     cout << "*" << " ";

    //     if (i != 0)
    //     {
    //         for (int j = 0; j < 2 * i - 1; j++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << "*" << " ";
    //     }

    //     cout << endl;
    // }

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << "  ";
    //     }
    //     cout << "*" << " ";

    //     if (i != n - 2)
    //     {
    //         for (int j = 0; j < 2*(n-i) - 5; j++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << "*" << " ";
    //     }

    //     cout << endl;
    // }

    // ***** Butterfly Pattern *****

    // ***** Problem 1 *****

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        for (int j = n; j > i + 1; j--)
        {
            cout << "  ";
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = n; j > n - i - 1; j--)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for(int i =0; i<n; i++){

        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        for (int j = n; j > n - i; j--)
        {
            cout << "  ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }

         for (int j = n; j > i ; j--)
        {
            cout << "* ";
        }
        cout<<endl;
    }
    return 0;
}