#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class doublyList
{
    Node *head;
    Node *tail;

public:
    doublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Invalid Operation." << endl;
            return;
        }

        Node *temp = head;

        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Invalid Operation." << endl;
            return;
        }

        Node *temp = tail;
        tail = temp->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    void print()
    {
        Node *temp = head;

        cout << "NULL <=> ";

        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    doublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.print();

    dll.push_back(4);
    dll.push_back(5);
    dll.push_back(6);

    dll.print();

    dll.pop_front();

    dll.print();

    dll.pop_back();

    dll.print();

    return 0;
}