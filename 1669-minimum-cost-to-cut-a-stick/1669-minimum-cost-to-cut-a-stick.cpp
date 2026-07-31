class Solution {
public:
int solve(vector<int>&cuts,int i,int j,int left,int right,vector<vector<int>>&dp){
    //base condition
    if(i>j) return 0;
    if(i==j) return right-left;

    if(dp[i][j]!=-1) return dp[i][j];

    int minimum=INT_MAX;
    for(int k=i;k<=j;k++){
        int total=0;
        total+=solve(cuts,i,k-1,left,cuts[k],dp);
        total+=solve(cuts,k+1,j,cuts[k],right,dp);
        total+=right-left;
        minimum=min(minimum,total);
    }
    return dp[i][j]=minimum;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int left=0,right=n;
        int minimum=INT_MAX;
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            int total=0;
            total+=solve(cuts,0,i-1,left,cuts[i],dp);
            total+=solve(cuts,i+1,m-1,cuts[i],right,dp);
            total+=right-left;
            minimum=min(minimum,total);
        }
        return minimum;
    }
};