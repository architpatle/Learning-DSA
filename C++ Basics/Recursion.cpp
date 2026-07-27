#include<iostream>
using namespace std;

// Print numbers from n to 1
void printNums(int n){

    if(n == 1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<" ";

    printNums(n-1);
}

// n Factorial
int nFactorial(int n){
    // !n = n* !(n-1)

    if(n==0){
        return 1;
    }

    return n*nFactorial(n-1);
}

// Sum of N numbers
int SumOfNNumbers(int n){
    // sum(n) = n + sum(n-1)

    if(n==1){
        return 1;
    }
    return n + SumOfNNumbers(n-1);
}
int main(){

    // printNums(4);

    // cout<<nFactorial(6);

    cout<<SumOfNNumbers(4);
    return 0;
}