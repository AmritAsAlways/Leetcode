class Solution {
public:

//Memoization solution
int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
    //base condition
    int n=nums.size();
    if(i==n) return 0;

    if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    if(prev==-1 || nums[prev]<nums[i]){
        int take=1+solve(nums,i+1,i,dp);
        int leave=solve(nums,i+1,prev,dp);
        return dp[i][prev+1]=max(take,leave);
    }
    return dp[i][prev+1]=solve(nums,i+1,prev,dp);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //memoization 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};