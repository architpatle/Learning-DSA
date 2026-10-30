#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            if (tempA == NULL)
            {
                tempA = headB;
            }
            else
            {
                tempA = tempA->next;
            }

            if (tempB == NULL)
            {
                tempB = headA;
            }
            else
            {
                tempB = tempB->next;
            }
        }

        return tempA;
    }
};

// Create a linked list from vector
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return NULL;

    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;

    for (int i = 1; i < values.size(); i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    return head;
}

// Get node at a particular index
ListNode *getNodeAt(ListNode *head, int index)
{
    int count = 0;

    while (head != NULL)
    {
        if (count == index)
            return head;

        head = head->next;
        count++;
    }

    return NULL;
}

// Print linked list
void printList(ListNode *head)
{
    if (head == NULL)
    {
        cout << "Empty list";
        return;
    }

    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
}

// Run a test case
void runTest(
    const vector<int> &valuesA,
    const vector<int> &valuesB,
    int skipA,
    int skipB)
{
    // Create the independent portions of both lists
    ListNode *headA = createList(valuesA);
    ListNode *headB = createList(valuesB);

    /*
        Create intersection.

        skipA = index in list A where intersection begins
        skipB = index in list B where intersection begins

        The nodes starting from A[skipA] and B[skipB]
        must become the SAME nodes.
    */

    if (skipA >= 0 && skipB >= 0)
    {
        ListNode *intersectionA = getNodeAt(headA, skipA);
        ListNode *intersectionB = getNodeAt(headB, skipB);

        if (intersectionA != NULL && intersectionB != NULL)
        {

            // Connect B to the shared portion of A
            if (skipB == 0)
            {
                headB = intersectionA;
            }
            else
            {
                ListNode *prevB = getNodeAt(headB, skipB - 1);
                prevB->next = intersectionA;
            }
        }
    }

    Solution sol;

    ListNode *intersection =
        sol.getIntersectionNode(headA, headB);

    cout << "List A: ";
    printList(headA);
    cout << endl;

    cout << "List B: ";
    printList(headB);
    cout << endl;

    if (intersection != NULL)
    {
        cout << "Intersection node: "
             << intersection->val << endl;
    }
    else
    {
        cout << "Intersection node: NULL" << endl;
    }

    cout << "-----------------------------" << endl;
}

int main()
{

    // Test Case 1
    // A: 4 -> 1 -> 8 -> 4 -> 5
    // B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    //
    // Intersection starts at node 8
    //
    // Expected: 8
    runTest(
        {4, 1, 8, 4, 5},
        {5, 6, 1, 8, 4, 5},
        2,
        3);

    // Test Case 2
    // A: 1 -> 2 -> 3 -> 4 -> 5
    // B: 9 -> 8 -> 4 -> 5
    //
    // Intersection starts at node 4
    //
    // Expected: 4
    runTest(
        {1, 2, 3, 4, 5},
        {9, 8, 4, 5},
        3,
        2);

    // Test Case 3
    // No intersection
    //
    // A: 1 -> 2 -> 3
    // B: 4 -> 5 -> 6
    //
    // Expected: NULL
    //
    // Use skip values outside the lists to indicate
    // that no connection should be created.
    runTest(
        {1, 2, 3},
        {4, 5, 6},
        -1,
        -1);

    // Test Case 4
    // Intersection happens at the head of B
    //
    // A: 1 -> 2 -> 3 -> 4
    // B: 9 -> 3 -> 4
    //
    // Expected: 3
    runTest(
        {1, 2, 3, 4},
        {9, 3, 4},
        2,
        1);

    // Test Case 5
    // Both lists share their entire structure
    //
    // A: 1 -> 2 -> 3
    // B: same nodes
    //
    // Expected: 1
    runTest(
        {1, 2, 3},
        {7, 2, 3},
        0,
        0);

    // Test Case 6
    // Intersection occurs at the last node
    //
    // A: 1 -> 2 -> 3
    // B: 4 -> 5 -> 3
    //
    // Expected: 3
    runTest(
        {1, 2, 3},
        {4, 5, 3},
        2,
        2);

    return 0;
}