#include <iostream>
using namespace std;

// Node structure
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Function where you will write your solution
ListNode *reverseList(ListNode *head)
{
    // Write your solution here
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    // Creating the linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    ListNode *head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Call your solution
    ListNode *reversedHead = reverseList(head);

    // Print reversed list
    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}