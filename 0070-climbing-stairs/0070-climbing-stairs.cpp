class Solution {
public:
int solve(int stair,int&n,vector<int>&v){
    if(stair>n) return 0;
    if(stair==n) return 1;

    if(v[stair]!=-1) return v[stair];

    return v[stair]=solve(stair+1,n,v)+solve(stair+2,n,v);
}
    int climbStairs(int n) {
        vector<int>v(n+1,-1);//number of ways to reach n from different stairs
        v[n]=0;
        solve(0,n,v);
        return v[0];
    }
};