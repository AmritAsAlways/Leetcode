/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
int solve(unordered_map<int,vector<int>>&subordinates,unordered_map<int,int>&values,int id){
    if(subordinates.find(id)==subordinates.end()) return values[id];

    int answer=values[id];
    int n=subordinates[id].size();
    for(int i=0;i<n;i++){
        answer+=solve(subordinates,values,subordinates[id][i]);
    }
    return answer;
}
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        unordered_map<int,vector<int>>subordinates;
        unordered_map<int,int>values;
        for(int i=0;i<n;i++){
            int id=employees[i]->id,value=employees[i]->importance;
            vector<int>v=employees[i]->subordinates;
            values[id]=value;
            subordinates[id]=v;
        }
        return solve(subordinates,values,id);
    }
};