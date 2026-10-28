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
    ListNode *removeElements(ListNode *head, int key)
    {
        if(head == NULL){
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr != NULL){
            if((curr->val == key) && (curr == head)){
                head = head->next;
                curr = head;
            } else if((curr->val == key) && (curr != head)){
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr -> next;
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
    // Remove elements from middle
    // ==========================================

    ListNode *head1 = createList({1, 2, 6, 3, 4, 5, 6});

    cout << "Test Case 1" << endl;

    cout << "Original: ";
    printList(head1);

    head1 = solution.removeElements(head1, 6);

    cout << "After removal: ";
    printList(head1);

    // Expected:
    // Original: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    // After removal: 1 -> 2 -> 3 -> 4 -> 5

    // ==========================================
    // Test Case 2
    // Remove elements from beginning
    // ==========================================

    ListNode *head2 = createList({7, 7, 7, 1, 2, 3});

    cout << "\nTest Case 2" << endl;

    cout << "Original: ";
    printList(head2);

    head2 = solution.removeElements(head2, 7);

    cout << "After removal: ";
    printList(head2);

    // Expected:
    // Original: 7 -> 7 -> 7 -> 1 -> 2 -> 3
    // After removal: 1 -> 2 -> 3

    // ==========================================
    // Test Case 3
    // Remove all elements
    // ==========================================

    ListNode *head3 = createList({5, 5, 5, 5});

    cout << "\nTest Case 3" << endl;

    cout << "Original: ";
    printList(head3);

    head3 = solution.removeElements(head3, 5);

    cout << "After removal: ";
    printList(head3);

    // Expected:
    // Original: 5 -> 5 -> 5 -> 5
    // After removal: Empty List

    // ==========================================
    // Test Case 4
    // Element doesn't exist
    // ==========================================

    ListNode *head4 = createList({1, 2, 3, 4, 5});

    cout << "\nTest Case 4" << endl;

    cout << "Original: ";
    printList(head4);

    head4 = solution.removeElements(head4, 10);

    cout << "After removal: ";
    printList(head4);

    // Expected:
    // Original: 1 -> 2 -> 3 -> 4 -> 5
    // After removal: 1 -> 2 -> 3 -> 4 -> 5

    // ==========================================
    // Test Case 5
    // Single node - node should be removed
    // ==========================================

    ListNode *head5 = createList({5});

    cout << "\nTest Case 5" << endl;

    cout << "Original: ";
    printList(head5);

    head5 = solution.removeElements(head5, 5);

    cout << "After removal: ";
    printList(head5);

    // Expected:
    // Original: 5
    // After removal: Empty List

    // ==========================================
    // Test Case 6
    // Single node - node should remain
    // ==========================================

    ListNode *head6 = createList({5});

    cout << "\nTest Case 6" << endl;

    cout << "Original: ";
    printList(head6);

    head6 = solution.removeElements(head6, 10);

    cout << "After removal: ";
    printList(head6);

    // Expected:
    // Original: 5
    // After removal: 5

    // ==========================================
    // Test Case 7
    // Empty list
    // ==========================================

    ListNode *head7 = createList({});

    cout << "\nTest Case 7" << endl;

    cout << "Original: ";
    printList(head7);

    head7 = solution.removeElements(head7, 1);

    cout << "After removal: ";
    printList(head7);

    // Expected:
    // Original: Empty List
    // After removal: Empty List

    return 0;
}