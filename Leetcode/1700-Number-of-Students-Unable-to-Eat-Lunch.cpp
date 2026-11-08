#include <iostream>
#include<vector>
#include <queue>
#include<stack>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    stack<int> st;
    queue<int> q;
    int consequtiveNotTaken = 0;

    for(int i =0; i<students.size(); i++){
        q.push(students[i]);
    }

    for(int i = sandwiches.size() - 1; i>=0; i--){
        st.push(sandwiches[i]);
    }

    while(!q.empty()){
        if(q.front() == st.top()){
            q.pop();
            st.pop();

            consequtiveNotTaken = 0;
        } else {
            int currStudent = q.front();

            q.pop();
            q.push(currStudent);

            consequtiveNotTaken++;
        }

        if(consequtiveNotTaken == q.size()){
            return q.size();
        }
    }

    return 0;

}

int main()
{
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};

    cout<< countStudents(students, sandwiches);

    return 0;
}