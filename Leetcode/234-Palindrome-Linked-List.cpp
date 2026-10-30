#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> arr;

        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        int left = 0, right = arr.size() - 1;

        while (left < right)
        {
            if (arr[left] != arr[right])
                return false;

            left++;
            right--;
        }

        return true;
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
    bool result = sol.isPalindrome(head);

    cout << "Input: ";
    printList(head);

    cout << "\nOutput: "
         << (result ? "true" : "false")
         << endl;

    cout << "-----------------------------" << endl;
}

int main()
{

    // Test Case 1
    // Input: [1,2,2,1]
    // Expected: true
    runTest({1, 2, 2, 1});

    // Test Case 2
    // Input: [1,2]
    // Expected: false
    runTest({1, 2});

    // Test Case 3
    // Single node
    // Input: [1]
    // Expected: true
    runTest({1});

    // Test Case 4
    // Odd number of nodes
    // Input: [1,2,3,2,1]
    // Expected: true
    runTest({1, 2, 3, 2, 1});

    // Test Case 5
    // Odd number of nodes - not palindrome
    // Input: [1,2,3,4,1]
    // Expected: false
    runTest({1, 2, 3, 4, 1});

    // Test Case 6
    // All values same
    // Input: [7,7,7,7]
    // Expected: true
    runTest({7, 7, 7, 7});

    // Test Case 7
    // Two identical nodes
    // Input: [5,5]
    // Expected: true
    runTest({5, 5});

    // Test Case 8
    // Two different nodes
    // Input: [5,6]
    // Expected: false
    runTest({5, 6});

    // Test Case 9
    // Longer palindrome
    // Input: [1,2,3,4,5,4,3,2,1]
    // Expected: true
    runTest({1, 2, 3, 4, 5, 4, 3, 2, 1});

    // Test Case 10
    // Longer non-palindrome
    // Input: [1,2,3,4,5,6]
    // Expected: false
    runTest({1, 2, 3, 4, 5, 6});

    return 0;
}