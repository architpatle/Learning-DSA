#include <iostream>

using namespace std;

// ==========================================
// Linked List Node
// ==========================================

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *nextNode)
    {
        val = x;
        next = nextNode;
    }
};

// ==========================================
// Solution
// ==========================================

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != NULL)
        {
            if (curr->val == prev->val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

// ==========================================
// Helper: Create Linked List
// ==========================================

ListNode *createList(initializer_list<int> values)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int value : values)
    {
        ListNode *newNode = new ListNode(value);

        if (head == nullptr)
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

// ==========================================
// Helper: Print Linked List
// ==========================================

void printList(ListNode *head)
{
    if (head == nullptr)
    {
        cout << "Empty List" << endl;
        return;
    }

    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// ==========================================
// Main
// ==========================================

int main()
{
    Solution solution;

    // ==========================================
    // Test Case 1
    // Multiple duplicates
    // ==========================================

    ListNode *head1 = createList({1, 1, 2, 3, 3});

    cout << "Test Case 1" << endl;

    cout << "Original: ";
    printList(head1);

    head1 = solution.deleteDuplicates(head1);

    cout << "After removing duplicates: ";
    printList(head1);

    // Expected:
    // Original: 1 -> 1 -> 2 -> 3 -> 3
    // After removing duplicates: 1 -> 2 -> 3

    // ==========================================
    // Test Case 2
    // All elements are duplicates
    // ==========================================

    ListNode *head2 = createList({1, 1, 1, 1, 1});

    cout << "\nTest Case 2" << endl;

    cout << "Original: ";
    printList(head2);

    head2 = solution.deleteDuplicates(head2);

    cout << "After removing duplicates: ";
    printList(head2);

    // Expected:
    // Original: 1 -> 1 -> 1 -> 1 -> 1
    // After removing duplicates: 1

    // ==========================================
    // Test Case 3
    // No duplicates
    // ==========================================

    ListNode *head3 = createList({1, 2, 3, 4, 5});

    cout << "\nTest Case 3" << endl;

    cout << "Original: ";
    printList(head3);

    head3 = solution.deleteDuplicates(head3);

    cout << "After removing duplicates: ";
    printList(head3);

    // Expected:
    // Original: 1 -> 2 -> 3 -> 4 -> 5
    // After removing duplicates: 1 -> 2 -> 3 -> 4 -> 5

    // ==========================================
    // Test Case 4
    // Single node
    // ==========================================

    ListNode *head4 = createList({7});

    cout << "\nTest Case 4" << endl;

    cout << "Original: ";
    printList(head4);

    head4 = solution.deleteDuplicates(head4);

    cout << "After removing duplicates: ";
    printList(head4);

    // Expected:
    // Original: 7
    // After removing duplicates: 7

    // ==========================================
    // Test Case 5
    // Empty list
    // ==========================================

    ListNode *head5 = createList({});

    cout << "\nTest Case 5" << endl;

    cout << "Original: ";
    printList(head5);

    head5 = solution.deleteDuplicates(head5);

    cout << "After removing duplicates: ";
    printList(head5);

    // Expected:
    // Original: Empty List
    // After removing duplicates: Empty List

    // ==========================================
    // Test Case 6
    // Negative values
    // ==========================================

    ListNode *head6 = createList({-3, -3, -2, -1, -1, 0, 2, 2});

    cout << "\nTest Case 6" << endl;

    cout << "Original: ";
    printList(head6);

    head6 = solution.deleteDuplicates(head6);

    cout << "After removing duplicates: ";
    printList(head6);

    // Expected:
    // Original: -3 -> -3 -> -2 -> -1 -> -1 -> 0 -> 2 -> 2
    // After removing duplicates: -3 -> -2 -> -1 -> 0 -> 2

    return 0;
}