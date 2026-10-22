#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> m;

    int limit;

    void addNode(Node *newNode)
    {
        Node *oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->prev = head;
        newNode->next = oldNext;
    }

    void deleteNode(Node *oldNode)
    {
        Node *oldPrev = oldNode->prev;
        Node *oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity)
    {
        limit = capacity;
        head->next = tail;
        tail->next = head;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }

        Node *ansNode = m[key];
        int ans = ansNode->value;

        m.erase(key);
        deleteNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value)
    {
        // Checking if any element with same key is present in map. If yes then delete it. Later new {key, value} will be added
        if (m.find(key) != m.end())
        {
            Node *oldNode = m[key];
            m.erase(key);
            deleteNode(oldNode);
        }

        // Delete LRU Element
        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

// ==========================================
// Main
// ==========================================

int main()
{

    // ==========================================
    // Test Case 1
    // Standard LeetCode Example
    // ==========================================

    cout << "========== Test Case 1 ==========" << endl;

    LRUCache cache1(2);

    cache1.put(1, 1);
    cache1.put(2, 2);

    cout << "get(1): " << cache1.get(1) << endl;
    // Expected: 1

    cache1.put(3, 3);

    cout << "get(2): " << cache1.get(2) << endl;
    // Expected: -1

    cache1.put(4, 4);

    cout << "get(1): " << cache1.get(1) << endl;
    // Expected: -1

    cout << "get(3): " << cache1.get(3) << endl;
    // Expected: 3

    cout << "get(4): " << cache1.get(4) << endl;
    // Expected: 4

    // ==========================================
    // Test Case 2
    // Updating an existing key
    // ==========================================

    cout << "\n========== Test Case 2 ==========" << endl;

    LRUCache cache2(2);

    cache2.put(1, 10);
    cache2.put(2, 20);

    cout << "get(1): " << cache2.get(1) << endl;
    // Expected: 10

    cache2.put(1, 100);

    cout << "get(1): " << cache2.get(1) << endl;
    // Expected: 100

    cache2.put(3, 30);

    cout << "get(2): " << cache2.get(2) << endl;
    // Expected: -1

    cout << "get(3): " << cache2.get(3) << endl;
    // Expected: 30

    // ==========================================
    // Test Case 3
    // Capacity = 1
    // ==========================================

    cout << "\n========== Test Case 3 ==========" << endl;

    LRUCache cache3(1);

    cache3.put(1, 10);

    cout << "get(1): " << cache3.get(1) << endl;
    // Expected: 10

    cache3.put(2, 20);

    cout << "get(1): " << cache3.get(1) << endl;
    // Expected: -1

    cout << "get(2): " << cache3.get(2) << endl;
    // Expected: 20

    // ==========================================
    // Test Case 4
    // Access changes LRU order
    // ==========================================

    cout << "\n========== Test Case 4 ==========" << endl;

    LRUCache cache4(3);

    cache4.put(1, 10);
    cache4.put(2, 20);
    cache4.put(3, 30);

    // Current order:
    // 3 -> 2 -> 1
    // 3 = Most Recently Used
    // 1 = Least Recently Used

    cout << "get(1): " << cache4.get(1) << endl;
    // Expected: 10

    // Now order becomes:
    // 1 -> 3 -> 2
    // 2 = Least Recently Used

    cache4.put(4, 40);

    cout << "get(2): " << cache4.get(2) << endl;
    // Expected: -1

    cout << "get(1): " << cache4.get(1) << endl;
    // Expected: 10

    cout << "get(3): " << cache4.get(3) << endl;
    // Expected: 30

    cout << "get(4): " << cache4.get(4) << endl;
    // Expected: 40

    // ==========================================
    // Test Case 5
    // Multiple updates
    // ==========================================

    cout << "\n========== Test Case 5 ==========" << endl;

    LRUCache cache5(2);

    cache5.put(1, 100);
    cache5.put(2, 200);

    cache5.put(1, 111);

    cout << "get(1): " << cache5.get(1) << endl;
    // Expected: 111

    cache5.put(3, 300);

    cout << "get(2): " << cache5.get(2) << endl;
    // Expected: -1

    cache5.put(4, 400);

    cout << "get(1): " << cache5.get(1) << endl;
    // Expected: -1

    cout << "get(3): " << cache5.get(3) << endl;
    // Expected: 300

    cout << "get(4): " << cache5.get(4) << endl;
    // Expected: 400

    return 0;
}