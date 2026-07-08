class Solution {
public:
using ll=long long;
const ll mod=1e9+7;
ll dp[2][24][401];

ll solve(string&s,bool tight,int index,int digitsum,int&minsum,int&maxsum){
    if(index==s.size()){
        if(minsum<=digitsum && digitsum<=maxsum) return 1;
        return 0;
    }

    if(dp[tight][index][digitsum]!=-1) return dp[tight][index][digitsum];

    int lowerbound=0,upperbound=(tight) ? (s[index]-'0') : 9;
    ll answer=0;
    for(int val=lowerbound;val<=upperbound;val++){
        //invalid case
        if(val+digitsum>maxsum) continue;
        answer+=solve(s,(tight && val==upperbound),index+1,digitsum+val,minsum,maxsum)%mod;
    }
    return dp[tight][index][digitsum]=answer;
}
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        ll a=solve(num2,true,0,0,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        ll b=solve(num1,true,0,0,min_sum,max_sum);
        a%=mod;
        b%=mod;
        ll answer=a-b;
        cout<<a<<" "<<b<<endl;
        int n=num1.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=num1[i]-'0';
        }
        if(min_sum<=sum && sum<=max_sum) answer++;
        return (answer + mod) % mod;
    }
};