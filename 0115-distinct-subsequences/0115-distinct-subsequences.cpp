class Solution {
public:
int solve(int i,int j,int&n,int&m,string&s,string&t,vector<vector<int>>&dp){
    //base condition
    if(j==m) return 1;
    if(i==n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    //if we can take the character
    int x=0,y=0;
    if(s[i]==t[j]){
        x=solve(i+1,j+1,n,m,s,t,dp);
    }

    //if we donot take the character
    y=solve(i+1,j,n,m,s,t,dp);

    return dp[i][j]=x+y;
}
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(n<m) return 0;
        return solve(0,0,n,m,s,t,dp);        
    }
};