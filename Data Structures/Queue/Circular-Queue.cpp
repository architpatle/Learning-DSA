#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int capacity, currSize;
    int front, rear;

public:
    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void push(int val)
    {
        if (currSize == capacity)
        {
            cout << "CQ is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "CQ is empty" << endl;
            return;
        }

        front = (front + 1) % capacity;
        currSize--;
    }

    int frontNum()
    {
        if (empty())
        {
            cout << "CQ is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        return currSize == 0;
    }

    void printArr()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

    cq.printArr();

    while (!cq.empty())
    {
        cout << cq.frontNum() << " ";
        cq.pop();
    }

    cout << endl;

    return 0;
}