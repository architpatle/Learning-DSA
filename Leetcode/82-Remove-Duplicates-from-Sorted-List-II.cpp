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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode dummy(0, head);

        ListNode *prev = &dummy;
        ListNode *curr = head;

        while (curr != NULL)
        {
            if ((curr->next != NULL) && (curr->val == curr->next->val))
            {
                while ((curr->next != NULL) && (curr->val == curr->next->val))
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

// Create linked list
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

// Run test case
void runTest(initializer_list<int> values)
{
    ListNode *head = createList(values);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "Output: ";
    printList(head);
    cout << endl;
}

int main()
{

    // Test Case 1
    // Input: [1,2,3,3,4,4,5]
    // Expected: [1,2,5]
    runTest({1, 2, 3, 3, 4, 4, 5});

    // Test Case 2
    // Input: [1,1,1,2,3]
    // Expected: [2,3]
    runTest({1, 1, 1, 2, 3});

    // Test Case 3
    // Input: [1,2,2,3,3,4]
    // Expected: [1,4]
    runTest({1, 2, 2, 3, 3, 4});

    // Test Case 4
    // All elements are duplicates
    // Input: [1,1,1,1]
    // Expected: Empty list
    runTest({1, 1, 1, 1});

    // Test Case 5
    // No duplicates
    // Input: [1,2,3,4,5]
    // Expected: [1,2,3,4,5]
    runTest({1, 2, 3, 4, 5});

    // Test Case 6
    // Duplicate at the beginning
    // Input: [1,1,2,3]
    // Expected: [2,3]
    runTest({1, 1, 2, 3});

    // Test Case 7
    // Duplicate at the end
    // Input: [1,2,3,3]
    // Expected: [1,2]
    runTest({1, 2, 3, 3});

    // Test Case 8
    // Single node
    // Input: [5]
    // Expected: [5]
    runTest({5});

    // Test Case 9
    // Empty list
    // Expected: Empty list
    runTest({});

    // Test Case 10
    // Negative values
    // Input: [-3,-3,-2,-1,-1,0,2,2,3]
    // Expected: [-2,0,3]
    runTest({-3, -3, -2, -1, -1, 0, 2, 2, 3});

    return 0;
}