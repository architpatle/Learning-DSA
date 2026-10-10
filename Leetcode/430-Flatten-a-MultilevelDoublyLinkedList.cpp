#include <iostream>
using namespace std;

/*
    Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int _val)
    {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
            return head;

        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                //flatten DLL
                Node *next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //Finding Tail
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                //attach tail with next ptr
                if (next != NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};

// ----------------------------------------
// Print the flattened doubly linked list
// ----------------------------------------

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val;

        if (temp->next != NULL)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << endl;
}

// ----------------------------------------
// Print list including child relationships
// ----------------------------------------

void printStructure(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "Node " << temp->val;

        if (temp->child != NULL)
            cout << " has child " << temp->child->val;

        cout << endl;

        temp = temp->next;
    }
}

int main()
{
    // =====================================================
    // TEST CASE 1
    //
    // Level 1:
    //
    // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    //           |
    //           7 <-> 8 <-> 9 <-> 10
    //                     |
    //                     11 <-> 12
    //
    // Expected flattened:
    //
    // 1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 9 <-> 11 <-> 12
    //      <-> 10 <-> 4 <-> 5 <-> 6
    // =====================================================

    Node *head1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    // Level 1
    head1->next = node2;
    node2->prev = head1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    // Child list of node 3
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);

    node7->next = node8;
    node8->prev = node7;

    node8->next = node9;
    node9->prev = node8;

    node9->next = node10;
    node10->prev = node9;

    node3->child = node7;

    // Child list of node 9
    Node *node11 = new Node(11);
    Node *node12 = new Node(12);

    node11->next = node12;
    node12->prev = node11;

    node9->child = node11;

    // =====================================================
    // TEST CASE 2
    //
    // Simple child list
    //
    // 1 <-> 2 <-> 3
    //      |
    //      4 <-> 5
    //
    // Expected:
    //
    // 1 <-> 2 <-> 4 <-> 5 <-> 3
    // =====================================================

    Node *head2 = new Node(1);
    Node *node2_2 = new Node(2);
    Node *node3_2 = new Node(3);

    head2->next = node2_2;
    node2_2->prev = head2;

    node2_2->next = node3_2;
    node3_2->prev = node2_2;

    Node *node4_2 = new Node(4);
    Node *node5_2 = new Node(5);

    node4_2->next = node5_2;
    node5_2->prev = node4_2;

    node2_2->child = node4_2;

    // =====================================================
    // TEST CASE 3
    //
    // No child list
    //
    // 1 <-> 2 <-> 3
    //
    // Expected:
    //
    // 1 <-> 2 <-> 3
    // =====================================================

    Node *head3 = new Node(1);
    Node *node2_3 = new Node(2);
    Node *node3_3 = new Node(3);

    head3->next = node2_3;
    node2_3->prev = head3;

    node2_3->next = node3_3;
    node3_3->prev = node2_3;

    // =====================================================
    // TEST CASE 4
    //
    // Single node with child
    //
    // 1
    // |
    // 2
    //
    // Expected:
    //
    // 1 <-> 2
    // =====================================================

    Node *head4 = new Node(1);
    Node *node2_4 = new Node(2);

    head4->child = node2_4;

    // =====================================================
    // SOLUTION
    // =====================================================

    Solution solution;

    // Test Case 1
    cout << "Test Case 1: ";
    Node *result1 = solution.flatten(head1);
    printList(result1);

    // Test Case 2
    cout << "Test Case 2: ";
    Node *result2 = solution.flatten(head2);
    printList(result2);

    // Test Case 3
    cout << "Test Case 3: ";
    Node *result3 = solution.flatten(head3);
    printList(result3);

    // Test Case 4
    cout << "Test Case 4: ";
    Node *result4 = solution.flatten(head4);
    printList(result4);

    return 0;
}