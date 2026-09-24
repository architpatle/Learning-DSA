#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // push_front()
    void push_front(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // pop front
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        Node *temp = head;

        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // pop back
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        Node *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // insert a node
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position";
            return;
        }

        if (pos = 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;

            if (temp->next == NULL)
            {
                cout << "Invalid position";
            }
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // search
    int search(int key)
    {
        Node *temp = head;

        int idx = 0;

        while (temp->next != NULL)
        {
            if (temp->data == key)
            {

                return idx + 1;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    // print linked list
    void print()
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(2);
    ll.push_front(4);
    ll.push_front(6);

    ll.print();

    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);

    ll.print();

    ll.pop_front();

    ll.print();

    ll.pop_back();

    ll.print();

    ll.insert(7, 2);

    ll.print();

    cout<<"Number found at position: "<<ll.search(7);

    return 0;
}