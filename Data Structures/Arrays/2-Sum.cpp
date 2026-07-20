#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> TwoSum(vector<int> arr, int target){
    unordered_map<int,int> m;
    vector<int> ans;

    for(int i = 0; i<arr.size(); i++){
        int first = arr[i];
        int second = target - first;

        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first] =i;

    }
   return ans; 
}

int main(){
    vector<int> arr = {5,2,3,7,8};
    int target = 15;

    vector<int> ans = TwoSum(arr, target);

    for(int val: ans){
        cout<<val<<" ";
    }

    return 0;
}