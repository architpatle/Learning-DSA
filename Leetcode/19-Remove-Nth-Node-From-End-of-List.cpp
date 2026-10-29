#include <iostream>
#include <initializer_list>
using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return head;

        ListNode dummy(0, head);

        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};

// Create linked list from initializer list
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

// Print linked list
void printList(ListNode *head)
{
    if (head == nullptr)
    {
        cout << "Empty list";
        return;
    }

    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }
}

// Test helper
void runTest(initializer_list<int> values, int n)
{
    ListNode *head = createList(values);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "n = " << n << " | Output: ";
    printList(head);
    cout << endl;
}

int main()
{

    // Test Case 1
    // Input: [1,2,3,4,5], n = 2
    // Expected: [1,2,3,5]
    runTest({1, 2, 3, 4, 5}, 2);

    // Test Case 2
    // Input: [1], n = 1
    // Expected: []
    runTest({1}, 1);

    // Test Case 3
    // Input: [1,2], n = 1
    // Expected: [1]
    runTest({1, 2}, 1);

    // Test Case 4
    // Input: [1,2], n = 2
    // Expected: [2]
    runTest({1, 2}, 2);

    // Test Case 5
    // Input: [1,2,3,4,5], n = 5
    // Expected: [2,3,4,5]
    runTest({1, 2, 3, 4, 5}, 5);

    // Test Case 6
    // Removing a middle node
    // Input: [10,20,30,40,50,60], n = 3
    // Expected: [10,20,30,50,60]
    runTest({10, 20, 30, 40, 50, 60}, 3);

    // Test Case 7
    // Duplicate values
    // Input: [5,5,5,5], n = 2
    // Expected: [5,5,5]
    runTest({5, 5, 5, 5}, 2);

    return 0;
}