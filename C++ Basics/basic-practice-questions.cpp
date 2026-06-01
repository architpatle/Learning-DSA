#include <iostream>
using namespace std;

int main()
{
    // ---- Sum of 2 nums ----

    // int num1, num2;

    // cout << "Enter number 1:";
    // cin >> num1;

    // cout << "Enter number 2:";
    // cin >> num2;

    // cout << "Sum of " << num1 << " & " << num2 << " is: " << num1 + num2;

    // ---- Checking if character is lowercase or uppercase

    // char ch;

    // cout << "Enter a character: ";
    // cin >> ch;

    // if (ch >= 'A' && ch <= 'Z')
    // {
    //     cout << "Uppercase";
    // }
    // else
    // {
    //     cout << "Lowercase"<<endl;
    // }

    // cout << (int)ch;

    // ---- Print 1 to N numners using while loop ----

    // int counter = 1, num;

    // cout << "Enter a number: ";
    // cin >> num;

    // while (counter <= num)
    // {
    //     cout << counter << endl;

    //     counter++;
    // }

    // ---- Sum of Numbers from 1 to n ----

    // int num, sum = 0;

    // cout << "Enter a num: ";
    // cin >> num;

    // for (int i = 1; i <= num; i++)
    // {
    //     sum = sum + i;
    // }

    // cout << "Sum of 1 to " << num << " is: " << sum;

    // ---- Sum of all odd nums from 1 to n ----

    // int num, sum=0;

    // cout<<"Enter a number: ";
    // cin>>num;

    // for(int i= 1; i<=num; i++) {
    //     if(i % 2 != 0){
    //         sum += i;
    //     }
    // }

    // cout<<"Sum of all Odd numbers from 1 to "<<num<<" are: "<<sum;

    // ---- Check if a number is Prime or Not ----

    // int num;
    // bool isPrime = true;

    // cout<<"enter a number: ";
    // cin>> num;

    // for(int i=2; i<num; i++){
    //     if(num%i == 0){
    //         isPrime = false;
    //         break;
    //     }
    // }

    // if(isPrime){
    //         cout<<num<<" is a prime number.";
    // } else{
    //         cout<<num<<" is not a prime number.";

    // }

    // ---- Star pattern problem ----

    // int width, height;

    // cout << "Enter width: ";
    // cin >> width;

    // cout << "Enter height: ";
    // cin >> height;

    // for (int j = 1; j <= height; j++)
    // {
    //     for (int i = 1; i <= width; i++)
    //     {
    //         cout << "* ";
    //     }

    //     cout << endl;
    // }


    // ---- Sum of all numbers from 1 to n which are divisible by 3 ----

    // int num, sum = 0;

    // cout<<"Enter a number: ";
    // cin>>num;

    // for(int i=1; i<=num; i++){
    //     if(i%3 == 0){
    //         sum += i;
    //     }
    // }

    // cout<<"Sum of all numbers between 1 & "<<num<<" which are divisble by 3 are: "<<sum;


    // ---- Print Factorial of number n ----

    int num, factorial =1;

    cout<<"Enter a number: ";
    cin>>num;

    for(int i=1; i<=num; i++){
        factorial *=i;
    }

    cout<<"Factorial of "<<num<<" is: "<<factorial;

    return 0;
}