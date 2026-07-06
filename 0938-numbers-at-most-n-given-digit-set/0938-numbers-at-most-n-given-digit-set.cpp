class Solution {
public:
int dp[2][11][2];
int solve(string&s,vector<bool>&digit,bool tight,int idx,bool leadingzero){
    //base condition
    if(idx==s.size()) return (leadingzero) ? 0 : 1;

    if(dp[tight][idx][leadingzero]!=-1) return dp[tight][idx][leadingzero];

    int lowerbound=0,upperbound=(tight==true) ? (s[idx]-'0') : 9;
    int answer=0;
    for(int val=lowerbound;val<=upperbound;val++){
        //invalid case
        if(leadingzero && val!=0 && !digit[val]) continue;
        if(!leadingzero && !digit[val]) continue;

        answer+=solve(s,digit,(tight && val==upperbound),idx+1,(leadingzero && val==0));
    }
    return dp[tight][idx][leadingzero]=answer;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        vector<bool>digit(10,false);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<digits.size();i++){
            digit[digits[i][0]-'0']=true;
        }
        return solve(s,digit,true,0,true);
    }
};