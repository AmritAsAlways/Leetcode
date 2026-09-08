class Solution {
public:
void solve(int&k,int&n,vector<int>v,vector<vector<int>>&ans,int sum,int num){
    if(v.size()==k || num==10){
        if(sum==n && v.size()==k) ans.push_back(v);
        return;
    }

    //take the number
    if(sum+num<=n){
        v.push_back(num);
        solve(k,n,v,ans,sum+num,num+1);
        v.pop_back();
    }

    //leave the number
    solve(k,n,v,ans,sum,num+1);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        //largest number that can be formed with k numbers 
        int largest=0,times=k,largestvalue=9;
        while(times>0){
            largest+=largestvalue;
            largestvalue--;
            times--;
        }
        if(n>largest) return {};
        vector<vector<int>>ans;
        vector<int>v;
        solve(k,n,v,ans,0,1);
        return ans;
    }
};