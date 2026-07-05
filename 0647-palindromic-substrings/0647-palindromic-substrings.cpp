class Solution {
public:
int solve(string&s,int i,int j,vector<vector<int>>&dp){
    //base condition
    int n=s.size();
    if(i>j) return 1;
    if(i>=n || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    solve(s,i+1,j,dp);
    solve(s,i,j-1,dp);
    if(s[i]==s[j]){
        if(solve(s,i+1,j-1,dp)) return dp[i][j]=1;
    }
    return dp[i][j]=0;
}
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(s,0,n-1,dp);
        int answer=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==1) answer++;
            }
        }
        return answer;
    }
};