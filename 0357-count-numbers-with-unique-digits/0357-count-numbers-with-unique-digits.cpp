class Solution {
public:
int solve(string&s,bool tight,int idx,vector<bool>&digit,bool leadingzero){
    //base condition
    if(idx==s.size()) return 1;

    int answer=0;
    int lowerbound=0,upperbound=9;
    for(int val=lowerbound;val<=upperbound;val++){
        //invalid case
        if(digit[val] && !leadingzero) continue;

        digit[val]=true;
        answer+=solve(s,(tight && val==upperbound),idx+1,digit,(leadingzero && val==0));
        digit[val]=false;
    }
    return answer;
}
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        n=pow(10,n);
        n--;
        string s=to_string(n);
        vector<bool>digit(10,false);
        return solve(s,true,0,digit,true);
    }
};