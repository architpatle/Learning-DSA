#include <iostream>
using namespace std;

// Solve using Binary Exponentiation

double myPow(double x, int n)
{
    int ans =1;

    if(n<0){
        x=1/x;
        n=-n;
    }
    while(n>0){
        if(n%2 == 1){
            ans*= x;
        }
        x *=x;
        n/=2;
    }

    return ans;

}

int main()
{
    double x = 3;
    int n = 5;

    cout<<myPow(x,n);
    return 0;
}