#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        unordered_map<Node *, Node *> m;

        Node *newHead = new Node(head->val);
        Node *oldTemp = head->next;
        Node *newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL)
        {
            Node *copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL)
        {
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Print the linked list
void printList(Node *head)
{
    // Store nodes so that we can find random indexes
    unordered_map<Node *, int> index;

    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        index[temp] = i++;
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        cout << "[" << temp->val << ", ";

        if (temp->random == NULL)
            cout << "NULL";
        else
            cout << index[temp->random];

        cout << "]";

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // --------------------------------
    // Test Case 1
    //
    // [7, NULL]
    // [13, 0]
    // [11, 4]
    // [10, 2]
    // [1, 0]
    // --------------------------------

    Node *head1 = new Node(7);
    head1->next = new Node(13);
    head1->next->next = new Node(11);
    head1->next->next->next = new Node(10);
    head1->next->next->next->next = new Node(1);

    // Set random pointers

    head1->random = NULL;

    head1->next->random = head1;

    head1->next->next->random =
        head1->next->next->next->next;

    head1->next->next->next->random =
        head1->next->next;

    head1->next->next->next->next->random =
        head1;

    // --------------------------------
    // Test Case 2
    //
    // [1, 1]
    // [2, 1]
    // --------------------------------

    Node *head2 = new Node(1);
    head2->next = new Node(2);

    head2->random = head2->next;
    head2->next->random = head2->next;

    // --------------------------------
    // Test Case 3
    //
    // Single node
    //
    // [1, NULL]
    // --------------------------------

    Node *head3 = new Node(1);
    head3->random = NULL;

    Solution solution;

    // --------------------------------
    // Test Case 1
    // --------------------------------

    cout << "Test Case 1 - Original: ";
    printList(head1);

    Node *copy1 = solution.copyRandomList(head1);

    cout << "Test Case 1 - Copy:     ";
    printList(copy1);

    // --------------------------------
    // Test Case 2
    // --------------------------------

    cout << "\nTest Case 2 - Original: ";
    printList(head2);

    Node *copy2 = solution.copyRandomList(head2);

    cout << "Test Case 2 - Copy:     ";
    printList(copy2);

    // --------------------------------
    // Test Case 3
    // --------------------------------

    cout << "\nTest Case 3 - Original: ";
    printList(head3);

    Node *copy3 = solution.copyRandomList(head3);

    cout << "Test Case 3 - Copy:     ";
    printList(copy3);

    return 0;
}