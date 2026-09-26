class Solution {
public:
int solve(string&s,int&i){
    int score=0,n=s.size();
    while(i<n){
        if(s[i]=='('){
            i++;
            score+=solve(s,i);
        }
        else{
            i++;
            if(score==0) return 1;
            else return score*2;
        }
    }
    return score;
}
    int scoreOfParentheses(string s) {
        int n=s.size(),score=0,i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                score+=solve(s,i);
            }
        }
        return score; 
    }
};