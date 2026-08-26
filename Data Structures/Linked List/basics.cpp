#include <iostream>
using namespace std;

// creating single node of linked list (Specifically a blueprint to creating multiple nodes using objects)
class Node
{
public:
    int data;   // actual data of the node
    Node *next; // address of next node

    Node(int val)
    {
        data = val;  // Constructor will receive some val, that will be stored in data
        next = NULL; // keeping the next ptr NULL only
    }
};

// creating a single linked list
class List
{       
    Node *head; // head ptr of the LL, points to 1st Node
    Node *tail; // tail ptr of the LL, points to last Node

public:
    List()
    {
        head = tail = NULL; // Initially LL will be empty so head = tail = NULL
    }

    // implementing push_front() function
    void push_front(int val){ // val-> value to be inserted in the ll
        Node *newNode = new Node(val); // dynamically creating a newNode with the help of Node class & storing it's memory address in newNode

        if(head == NULL){ // if ll is empty then adding the 1st node
            head = tail = newNode;
            return;
        } else { // if node(s) already exists in ll
            newNode ->next = head; // making the newNode point to the existing head node. (As a result 1st Node becomes 2nd and new node becomes 1st)
            head = newNode; //  making the head point to newNode
        }
    }

    // function to print the LL
    void printLL(){
        Node *temp = head; // creating a temp ptr to store actual head ptr value

        while(temp!=NULL){ // to traverse head to tail(NULL)
            cout<<temp->data<<"->"; // printing the data 
            temp = temp->next; // assigning next node ptr to temp
        }
        cout<<"NULL"<<endl; // upong reaching the last node
    }
};

int main()
{ List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.printLL();
    return 0;
}