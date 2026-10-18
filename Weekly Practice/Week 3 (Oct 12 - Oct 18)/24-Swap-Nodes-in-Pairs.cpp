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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *prev = NULL;

        while (first != NULL && second != NULL)
        {
            ListNode *third = second->next;

            second->next = first;
            first->next = third;

            if (prev != NULL)
            {
                prev->next = second;
            }
            else
            {
                head = second;
            }

            prev = first;
            first = third;

            if (third != NULL)
            {
                second = third->next;
            }
            else
            {
                second = NULL;
            }
        }

        return head;
    }
};

// ----------------------------------------
// Helper function to create a linked list
// ----------------------------------------

ListNode *createList(int values[], int n)
{
    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(values[0]);
    ListNode *tail = head;

    for (int i = 1; i < n; i++)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
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
    // 1 -> 2 -> 3 -> 4
    //
    // Expected:
    // 2 -> 1 -> 4 -> 3
    // =====================================================

    int values1[] = {1, 2, 3, 4};

    ListNode *head1 = createList(values1, 4);

    cout << "Test Case 1:" << endl;
    cout << "Original: ";
    printList(head1);

    ListNode *result1 = solution.swapPairs(head1);

    cout << "Result:   ";
    printList(result1);

    // =====================================================
    // TEST CASE 2
    //
    // 1 -> 2 -> 3
    //
    // Expected:
    // 2 -> 1 -> 3
    // =====================================================

    int values2[] = {1, 2, 3};

    ListNode *head2 = createList(values2, 3);

    cout << "\nTest Case 2:" << endl;
    cout << "Original: ";
    printList(head2);

    ListNode *result2 = solution.swapPairs(head2);

    cout << "Result:   ";
    printList(result2);

    // =====================================================
    // TEST CASE 3
    //
    // 1 -> 2
    //
    // Expected:
    // 2 -> 1
    // =====================================================

    int values3[] = {1, 2};

    ListNode *head3 = createList(values3, 2);

    cout << "\nTest Case 3:" << endl;
    cout << "Original: ";
    printList(head3);

    ListNode *result3 = solution.swapPairs(head3);

    cout << "Result:   ";
    printList(result3);

    // =====================================================
    // TEST CASE 4
    //
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    //
    // Expected:
    // 2 -> 1 -> 4 -> 3 -> 6 -> 5
    // =====================================================

    int values4[] = {1, 2, 3, 4, 5, 6};

    ListNode *head4 = createList(values4, 6);

    cout << "\nTest Case 4:" << endl;
    cout << "Original: ";
    printList(head4);

    ListNode *result4 = solution.swapPairs(head4);

    cout << "Result:   ";
    printList(result4);

    // =====================================================
    // TEST CASE 5
    //
    // Single node
    //
    // 1
    //
    // Expected:
    // 1
    // =====================================================

    int values5[] = {1};

    ListNode *head5 = createList(values5, 1);

    cout << "\nTest Case 5:" << endl;
    cout << "Original: ";
    printList(head5);

    ListNode *result5 = solution.swapPairs(head5);

    cout << "Result:   ";
    printList(result5);

    // =====================================================
    // TEST CASE 6
    //
    // Empty list
    //
    // Expected:
    // Empty list
    // =====================================================

    ListNode *head6 = NULL;

    cout << "\nTest Case 6:" << endl;
    cout << "Original: Empty list" << endl;

    ListNode *result6 = solution.swapPairs(head6);

    cout << "Result:   ";

    if (result6 == NULL)
        cout << "Empty list" << endl;
    else
        printList(result6);

    return 0;
}