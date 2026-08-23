#include <iostream>
using namespace std;

class Shape
{ // abstract class
    virtual void draw() = 0; // Pure Virtual Function
};

class Circle
{

public:
    void draw()
    {
        cout << "Drawing a circle." << endl;
    }
};

int main()
{
    Circle s1;

    s1.draw();

    return 0;
}