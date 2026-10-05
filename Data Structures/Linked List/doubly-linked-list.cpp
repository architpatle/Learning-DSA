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

    void pushFront(int val)
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

    void pushBack(int val)
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

    void popFront(){
        if (head==NULL){
            cout<<"DLL is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head!=NULL){
            head->prev = NULL;
        }

        temp->next = NULL;

        delete temp;
    }

    void popBack(){
        if(head == NULL){
            cout<<"DLL is empty"<<endl;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if(tail!=NULL){
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    // print linked list
    void print()
    {
        Node *temp = head;

        cout << "NULL <=> ";

        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL " << endl;
    }
};

int main()
{
    doublyList dll;

    dll.pushFront(1);
    dll.pushFront(2);
    dll.pushFront(3);

    dll.print();

    dll.pushBack(4);
    dll.pushBack(5);
    dll.pushBack(6);

    dll.print();

    dll.popFront();

    dll.print();

    dll.popFront();

    dll.print();

    dll.popBack();

    dll.print();

    dll.popBack();

    dll.print();

    return 0;
}