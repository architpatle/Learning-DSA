#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers
{
public:
    vector<int> nums;

    ProductOfNumbers()
    {
        // Initialize your data structure here
    }

    void add(int num)
    {
        nums.push_back(num);
    }

    int getProduct(int k)
    {
        int ans = 1;

        for(int i = nums.size() - 1; i>=0 && k>0; i-- && k--){
            ans*=nums[i];
        }
        return ans;
    }
};

void runTest()
{
    ProductOfNumbers *obj = new ProductOfNumbers();

    vector<pair<string, int>> operations = {
        {"add", 3},
        {"add", 0},
        {"add", 2},
        {"add", 5},
        {"add", 4}};

    vector<pair<int, int>> queries = {
        {2, 20},
        {3, 40},
        {4, 0},
        {2, 20}};

    int queryIndex = 0;

    cout << "Test 1:\n";

    for (int i = 0; i < operations.size(); i++)
    {
        obj->add(operations[i].second);
        cout << "add(" << operations[i].second << ")\n";

        if (i == 4)
        {
            while (queryIndex < queries.size())
            {
                int k = queries[queryIndex].first;
                int expected = queries[queryIndex].second;

                int result = obj->getProduct(k);

                cout << "getProduct(" << k << ") = " << result
                     << " | Expected: " << expected << "\n";

                queryIndex++;
                if (queryIndex == 2)
                    break;
            }
        }
    }

    delete obj;
}

void runTest2()
{
    ProductOfNumbers obj;

    cout << "\nTest 2:\n";

    obj.add(1);
    obj.add(2);
    obj.add(3);
    cout << "getProduct(3) = " << obj.getProduct(3)
         << " | Expected: 6\n";

    obj.add(4);
    cout << "getProduct(2) = " << obj.getProduct(2)
         << " | Expected: 12\n";

    obj.add(5);
    cout << "getProduct(2) = " << obj.getProduct(2)
         << " | Expected: 20\n";

    obj.add(0);
    obj.add(6);
    cout << "getProduct(1) = " << obj.getProduct(1)
         << " | Expected: 6\n";

    cout << "getProduct(2) = " << obj.getProduct(2)
         << " | Expected: 0\n";
}

int main()
{
    runTest();
    runTest2();

    return 0;
}