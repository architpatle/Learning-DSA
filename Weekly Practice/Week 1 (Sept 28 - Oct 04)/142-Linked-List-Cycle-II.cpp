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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle == false)
        {
            return NULL;
        }

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// Helper function to print the result
void printResult(ListNode *result)
{
    if (result == NULL)
    {
        cout << "No cycle" << endl;
    }
    else
    {
        cout << "Cycle starts at node with value: "
             << result->val << endl;
    }
}

int main()
{
    // --------------------------------
    // Test Case 1: Cycle exists
    // 3 -> 2 -> 0 -> -4
    //      ↑         |
    //      └─────────┘
    // --------------------------------

    ListNode *head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);

    // -4 points back to 2
    head1->next->next->next->next = head1->next;

    // --------------------------------
    // Test Case 2: No Cycle
    // 1 -> 2 -> 3 -> NULL
    // --------------------------------

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = NULL;

    // --------------------------------
    // Test Case 3: Cycle starts at head
    // 1 -> 2 -> 3
    // ↑         |
    // └─────────┘
    // --------------------------------

    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);

    // 3 points back to 1
    head3->next->next->next = head3;

    Solution solution;

    cout << "Test Case 1: ";
    printResult(solution.detectCycle(head1));

    cout << "Test Case 2: ";
    printResult(solution.detectCycle(head2));

    cout << "Test Case 3: ";
    printResult(solution.detectCycle(head3));

    return 0;
}