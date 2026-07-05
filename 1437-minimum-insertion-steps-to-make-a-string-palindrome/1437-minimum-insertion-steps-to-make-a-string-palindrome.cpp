class Solution {
public:
  int solve(string&s,int i,int j,vector<vector<int>>&dp){
      //base condition
      int n=s.size();
      if(i>n || j<0) return 0;
      if(i>j) return 0;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s[i]==s[j]){
          int a=solve(s,i+1,j-1,dp);
          return dp[i][j]=a;
      }
      
      int x=solve(s,i+1,j,dp)+1;
      int y=solve(s,i,j-1,dp)+1;
      return dp[i][j]=min(x,y);
  }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};