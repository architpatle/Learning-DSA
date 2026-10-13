#include <iostream>
using namespace std;

/*
    Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;

        // check if k nodes exists
        while (count < k)
        {
            if (temp == NULL)
            {
                return head;
            }
            else
            {
                temp = temp->next;
                count++;
            }
        }

        // recursively call the rest of the LL
        ListNode *prevNode = reverseKGroup(temp, k);

        // reverse current group
        temp = head;
        count = 0;

        while (count < k)
        {
            ListNode *next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;

            count++;
        }

        return prevNode;
    }
};

// ----------------------------------------
// Helper function to create a linked list
// ----------------------------------------

ListNode *createList()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        ListNode *newNode = new ListNode(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// ----------------------------------------
// Print linked list
// ----------------------------------------

void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Solution solution;

    // =====================================================
    // TEST CASE 1
    //
    // List:
    // 1 -> 2 -> 3 -> 4 -> 5
    //
    // k = 2
    //
    // Expected:
    // 2 -> 1 -> 4 -> 3 -> 5
    // =====================================================

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    int k1 = 2;

    cout << "Test Case 1:" << endl;
    cout << "Original: ";
    printList(head1);

    ListNode *result1 = solution.reverseKGroup(head1, k1);

    cout << "Result:   ";
    printList(result1);

    // =====================================================
    // TEST CASE 2
    //
    // List:
    // 1 -> 2 -> 3 -> 4 -> 5
    //
    // k = 3
    //
    // Expected:
    // 3 -> 2 -> 1 -> 4 -> 5
    // =====================================================

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    int k2 = 3;

    cout << "\nTest Case 2:" << endl;
    cout << "Original: ";
    printList(head2);

    ListNode *result2 = solution.reverseKGroup(head2, k2);

    cout << "Result:   ";
    printList(result2);

    // =====================================================
    // TEST CASE 3
    //
    // List:
    // 1 -> 2 -> 3 -> 4
    //
    // k = 4
    //
    // Expected:
    // 4 -> 3 -> 2 -> 1
    // =====================================================

    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);

    int k3 = 4;

    cout << "\nTest Case 3:" << endl;
    cout << "Original: ";
    printList(head3);

    ListNode *result3 = solution.reverseKGroup(head3, k3);

    cout << "Result:   ";
    printList(result3);

    // =====================================================
    // TEST CASE 4
    //
    // List:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    //
    // k = 2
    //
    // Expected:
    // 2 -> 1 -> 4 -> 3 -> 6 -> 5
    // =====================================================

    ListNode *head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    head4->next->next->next = new ListNode(4);
    head4->next->next->next->next = new ListNode(5);
    head4->next->next->next->next->next = new ListNode(6);

    int k4 = 2;

    cout << "\nTest Case 4:" << endl;
    cout << "Original: ";
    printList(head4);

    ListNode *result4 = solution.reverseKGroup(head4, k4);

    cout << "Result:   ";
    printList(result4);

    // =====================================================
    // TEST CASE 5
    //
    // List:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    //
    // k = 3
    //
    // Expected:
    // 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7
    // =====================================================

    ListNode *head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    head5->next->next->next = new ListNode(4);
    head5->next->next->next->next = new ListNode(5);
    head5->next->next->next->next->next = new ListNode(6);
    head5->next->next->next->next->next->next = new ListNode(7);

    int k5 = 3;

    cout << "\nTest Case 5:" << endl;
    cout << "Original: ";
    printList(head5);

    ListNode *result5 = solution.reverseKGroup(head5, k5);

    cout << "Result:   ";
    printList(result5);

    return 0;
}