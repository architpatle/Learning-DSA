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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode *temp = head;
        ListNode *tail = NULL;
        int n = 1;

        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }

        tail = temp;

        k = k % n;

        for(int i =0; i<k; i++){
            tail->next = head;
            head = tail;

            while(tail -> next != head ){
                tail = tail->next;
            }
            tail ->next = NULL;
        }

        return head;
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
void runTest(initializer_list<int> values, int k)
{
    ListNode *head = createList(values);

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "k = " << k << " | Output: ";
    printList(head);
    cout << endl;
}

int main()
{

    // Test Case 1
    // Input: [1,2,3,4,5], k = 2
    // Expected: [4,5,1,2,3]
    runTest({1, 2, 3, 4, 5}, 2);

    // Test Case 2
    // Input: [0,1,2], k = 4
    // Expected: [2,0,1]
    runTest({0, 1, 2}, 4);

    // Test Case 3
    // k = 0
    // Input: [1,2,3,4], k = 0
    // Expected: [1,2,3,4]
    runTest({1, 2, 3, 4}, 0);

    // Test Case 4
    // k equals length
    // Input: [1,2,3,4,5], k = 5
    // Expected: [1,2,3,4,5]
    runTest({1, 2, 3, 4, 5}, 5);

    // Test Case 5
    // k is multiple of length
    // Input: [1,2,3,4,5], k = 10
    // Expected: [1,2,3,4,5]
    runTest({1, 2, 3, 4, 5}, 10);

    // Test Case 6
    // Single node
    // Input: [7], k = 100
    // Expected: [7]
    runTest({7}, 100);

    // Test Case 7
    // Two nodes
    // Input: [1,2], k = 1
    // Expected: [2,1]
    runTest({1, 2}, 1);

    // Test Case 8
    // Two nodes, k > length
    // Input: [1,2], k = 5
    // Expected: [2,1]
    runTest({1, 2}, 5);

    // Test Case 9
    // Negative values
    // Input: [-1,-2,-3,-4], k = 2
    // Expected: [-3,-4,-1,-2]
    runTest({-1, -2, -3, -4}, 2);

    // Test Case 10
    // Empty list
    // Expected: Empty list
    runTest({}, 3);

    // Test Case 11
    // Large k
    // Input: [1,2,3,4,5], k = 2000000000
    // 2000000000 % 5 = 0
    // Expected: [1,2,3,4,5]
    runTest({1, 2, 3, 4, 5}, 2000000000);

    return 0;
}