class Solution {
public:
int dp[2][11][2][1025][2];
int solve(string&s,bool tight,int idx,bool repeated,int bitmask,bool leadingzero){
    //base condition
    if(idx==s.size()) return repeated;

    if(dp[tight][idx][repeated][bitmask][leadingzero]!=-1) return dp[tight][idx][repeated][bitmask][leadingzero];

    int lowerbound=0,upperbound=(tight) ? (s[idx]-'0'): 9;
    int answer=0;
    for(int dig=lowerbound;dig<=upperbound;dig++){
        //if the dig==0 and leadingzero is also true
        if(leadingzero && dig==0){
            answer+=solve(s,(tight && dig==upperbound),idx+1,repeated,bitmask,leadingzero);
        }
        else{ 
            bool isrepeated=bitmask & (1<<dig);
            answer+=solve(s,(tight && dig==upperbound),idx+1,(repeated || isrepeated),bitmask | (1<<dig),(leadingzero && dig==0));
        }
    }
    return dp[tight][idx][repeated][bitmask][leadingzero]=answer;
}
    int numDupDigitsAtMostN(int n) {
        // digit dp + bitmask
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,true,0,0,0,1);
    }
};