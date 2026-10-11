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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    // --------------------------------
    // Test Case 1: No Cycle
    // --------------------------------

    ListNode *head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = NULL;

    // --------------------------------
    // Test Case 2: Has Cycle
    // --------------------------------

    ListNode *head2 = new ListNode(3);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(0);
    head2->next->next->next = new ListNode(-4);

    // Create cycle:
    // -4 -> 2
    head2->next->next->next->next = head2->next;

    Solution solution;

    cout << "Test Case 1: ";

    if (solution.hasCycle(head1))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Test Case 2: ";

    if (solution.hasCycle(head2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}