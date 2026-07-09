class Solution {
public:
int dp[2][33][3][2];
int solve(string&s,bool tight,int idx,int prev,bool leadingzero){
    //base condition
    if(idx==s.size()) return 1;

    if(dp[tight][idx][prev][leadingzero]!=-1) return dp[tight][idx][prev][leadingzero];

    int lowerbound=0,upperbound=(tight) ? (s[idx]-'0') : 1;
    int answer=0;
    for(int digit=lowerbound;digit<=upperbound;digit++){
        //invalid case
        if(!leadingzero && digit==prev && prev==1) continue;
        answer+=solve(s,(tight && digit==upperbound),idx+1,digit,(leadingzero && digit==0));
    }
    return dp[tight][idx][prev][leadingzero]=answer;
}
    int findIntegers(int n) {
        string s="";
        while(n>0){
            int r=n%2;
            n/=2;
            if(r==1) s='1'+s;
            else s='0'+s;
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,true,0,2,true);
    }
};