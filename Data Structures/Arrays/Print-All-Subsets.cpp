#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i)
{
    // base condition
    if(i == arr.size()){
        for(int val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    //include the i^th element
    ans.push_back(arr[i]);
    printSubsets(arr,ans,i+1);

    // exclude the i^th element
    ans.pop_back();
    printSubsets(arr,ans,i+1);


}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    printSubsets(arr, ans, 0);

    
    return 0;
}