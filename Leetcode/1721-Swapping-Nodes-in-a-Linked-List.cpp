#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *first = head;
        ListNode *second = head;

        int i = 1;

        while (i < k)
        {
            first = first->next;
            i++;
        }

        int n = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }

        int j = n - k + 1;
        i = 1;

        while (i < j)
        {
            second = second->next;
            i++;
        }

        int val = first->val;
        first->val = second->val;
        second->val = val;

        return head;
    }
};

// Create linked list from vector
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
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

    ListNode *current = head;

    while (current != nullptr)
    {
        cout << current->val;

        if (current->next != nullptr)
            cout << " -> ";

        current = current->next;
    }
}

// Run a test case
void runTest(vector<int> values, int k)
{
    ListNode *head = createList(values);

    Solution sol;
    ListNode *result = sol.swapNodes(head, k);

    cout << "Input: ";
    printList(head);

    cout << "\nk = " << k;

    cout << "\nOutput: ";
    printList(result);

    cout << "\n-----------------------------\n";
}

int main()
{

    // Test 1
    runTest({1, 2, 3, 4, 5}, 2);
    // Expected: 1 -> 4 -> 3 -> 2 -> 5

    // Test 2
    runTest({1, 2, 3, 4, 5}, 1);
    // Expected: 5 -> 2 -> 3 -> 4 -> 1

    // Test 3
    runTest({1, 2, 3, 4, 5}, 5);
    // Expected: 5 -> 2 -> 3 -> 4 -> 1

    // Test 4
    runTest({1, 2, 3, 4, 5, 6}, 3);
    // Expected: 1 -> 2 -> 4 -> 3 -> 5 -> 6

    // Test 5
    runTest({7}, 1);
    // Expected: 7

    // Test 6
    runTest({1, 2}, 1);
    // Expected: 2 -> 1

    // Test 7
    runTest({1, 2}, 2);
    // Expected: 2 -> 1

    // Test 8
    runTest({10, 20, 30, 40, 50, 60, 70}, 4);
    // Expected: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70
    // k = 4 means both nodes are the same middle node

    // Test 9
    runTest({5, 10, 15, 20, 25, 30}, 2);
    // Expected: 5 -> 25 -> 15 -> 20 -> 10 -> 30

    return 0;
}