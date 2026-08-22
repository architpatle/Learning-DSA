#include<iostream>
using namespace std;

class Print{

    public:

    void show(int x){
        cout<<"int: "<<x;
    }

    void show(char x){
        cout<<"char: "<<x;
    }
};

int main(){
    Print p1;

    p1.show('c');

    return 0;
}