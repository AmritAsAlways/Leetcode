class Solution {
public:
int dp[2][11][11];
int solve(string&s,bool tight,int idx,int count){
    //base condition
    if(idx==s.size()) return count;

    if(dp[tight][idx][count]!=-1) return dp[tight][idx][count];

    int lowerbound=0,upperbound=(tight==true) ? (s[idx]-'0') : 9;
    int answer=0;
    for(int val=lowerbound;val<=upperbound;val++){
        if(val==1) count++;
        answer+=solve(s,(tight && val==upperbound),idx+1,count);
        if(val==1) count--;
    }
    return dp[tight][idx][count]=answer;
}
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string s=to_string(n);
        return solve(s,true,0,0);
    }
};