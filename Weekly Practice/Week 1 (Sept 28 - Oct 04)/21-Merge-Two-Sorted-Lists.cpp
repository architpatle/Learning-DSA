#include <iostream>
using namespace std;

/*
    Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->val <= head2->val)
        {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // --------------------------------
    // Test Case 1
    //
    // List 1: 1 -> 2 -> 4
    // List 2: 1 -> 3 -> 4
    //
    // Expected:
    // 1 -> 1 -> 2 -> 3 -> 4 -> 4
    // --------------------------------

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // --------------------------------
    // Test Case 2
    //
    // List 1: NULL
    // List 2: 0 -> 5
    //
    // Expected:
    // 0 -> 5
    // --------------------------------

    ListNode *list3 = NULL;

    ListNode *list4 = new ListNode(0);
    list4->next = new ListNode(5);

    // --------------------------------
    // Test Case 3
    //
    // List 1: 1 -> 3 -> 5
    // List 2: 2 -> 4 -> 6
    //
    // Expected:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // --------------------------------

    ListNode *list5 = new ListNode(1);
    list5->next = new ListNode(3);
    list5->next->next = new ListNode(5);

    ListNode *list6 = new ListNode(2);
    list6->next = new ListNode(4);
    list6->next->next = new ListNode(6);

    Solution solution;

    // Test Case 1
    cout << "Test Case 1: ";
    ListNode *result1 = solution.mergeTwoLists(list1, list2);
    printList(result1);

    // Test Case 2
    cout << "Test Case 2: ";
    ListNode *result2 = solution.mergeTwoLists(list3, list4);
    printList(result2);

    // Test Case 3
    cout << "Test Case 3: ";
    ListNode *result3 = solution.mergeTwoLists(list5, list6);
    printList(result3);

    return 0;
}