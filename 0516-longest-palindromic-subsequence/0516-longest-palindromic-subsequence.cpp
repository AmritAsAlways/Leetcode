class Solution {
public:
int solve(string&s,int i,int j,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(i==j) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    //if both character are same
    if(s[i]==s[j]){
        int x=2+solve(s,i+1,j-1,dp);
        return dp[i][j]=x;
    }

    int x=solve(s,i+1,j,dp);
    int y=solve(s,i,j-1,dp);
    return dp[i][j]=max(x,y);
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};