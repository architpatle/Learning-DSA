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
    void push_front(int val)
    {                                  // val-> value to be inserted in the ll
        Node *newNode = new Node(val); // dynamically creating a newNode with the help of Node class & storing it's memory address in newNode

        if (head == NULL)
        { // if ll is empty then adding the 1st node
            head = tail = newNode;
            return;
        }
        else
        {                         // if node(s) already exists in ll
            newNode->next = head; // making the newNode point to the existing head node. (As a result 1st Node becomes 2nd and new node becomes 1st)
            head = newNode;       //  making the head point to newNode
        }
    }

    // implementing push_back() function
    void push_back(int val)
    {
        Node *newNode = new Node(val); // dynamically creating a newNode with the help of Node class & storing it's memory address in newNode

        if (head == NULL)
        { // if ll is empty then adding the 1st node
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode; // Initially tail-> NULL, so we are making tail point to newNode
            tail = newNode;       // Now newNode should be tail. Hence, tail points to newNode.
        }
    }

    // implementing pop_front() function
    void pop_front()
    {
        if (head == NULL) // checking if the ll is empty
        {
            cout << "LL is empty";
            return;
        }

        Node *temp = head; // creating a temp node which is storing the head pointer value
        head = head->next; // now head pointer is storing the value of next(2nd) node. So, 2nd Node becomes 1st Node now.
        temp->next = NULL; // assigning the previous head to NULL via temp
        delete temp;       // now clearing the dynamic memory assigned to temp(1st node).
    }

    // implementing pop_back() function
    void pop_back()
    {
        if (head == NULL) // checking if the ll is empty
        {
            cout << "LL is empty";
            return;
        }

        Node *temp = head;         // creating a temp node which is storing the head pointer value
        while (temp->next != tail) // traversing till the 2nd last node(which is pointing to the last node(same as tail))
        {
            temp = temp->next; // updating node
        }
        temp->next = NULL; // making the 2nd last node point to NULL
        delete tail;       // deleting the previous tail pointer value
        tail = temp;       // assigning new tail node (previously 2nd last node) pointer to tail
    }

    // implementing insert() function
    void insert(int val, int pos)
    {
        if (pos < 0) // checking invalid position insertion
        {
            cout << "Invalid Position!";
        }
        if (pos == 0)
        {
            push_front(val); // calling push_front() if pos = 0
            return;
        }

        Node *temp = head; // creating a temp node which is storing the head pointer value

        for (int i = 0; i < pos - 1; i++) // traversing till the point when temp node is at the postion where new node is to be there
        {
            temp = temp->next; // updating node
 
            if (temp->next == NULL) // checking invalid position insertion
            {
                cout << "Invalid Position!";
            }
        }

        Node *newNode = new Node(val); // creating a new node
        newNode->next = temp->next; // making the newnode point to the next node (where temp is pointing)
        temp->next = newNode; // now temp node is pointing to the newnode
    }

    // implementing search() function
    int search(int key){
        Node *temp = head;
        int idx=0;

        while(temp->next !=NULL){
            if(temp->data == key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
    }

    // function to print the LL
    void printLL()
    {
        Node *temp = head; // creating a temp ptr to store actual head ptr value

        while (temp != NULL)
        {                               // to traverse head to tail(NULL)
            cout << temp->data << "->"; // printing the data
            temp = temp->next;          // assigning next node ptr to temp
        }
        cout << "NULL" << endl; // upon reaching the last node
    }
};

int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.push_back(7);
    ll.push_back(8);

    ll.printLL();

    ll.pop_front();
    ll.printLL();

    ll.pop_back();
    ll.printLL();

    ll.insert(99, 2);
    ll.printLL();

    cout<<ll.search(1);

    return 0;
}