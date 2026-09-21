class Solution {
public:
    int numTilings(int n) {
        if(n==1 || n==2) return n;
        if(n==3) return 5;
        long long mod=1e9+7;
        //using the formula of f(n)=2*f(n-1)+f(n-3);
        vector<long long>dp(n,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<n;i++){
            dp[i]=2*dp[i-1]%mod+dp[i-3]%mod;
            dp[i]%=mod;
        }
        //dp[n] is the answer
        long long answer=2*dp[n-1]%mod+dp[n-3]%mod;
        answer%=mod;
        return (int)answer;
    }
};