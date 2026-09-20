class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(),i=0,open=0;
        bool start=true;
        string ans="";
        while(i<n){
            if(s[i]=='('){
                if(!start) ans+=s[i];
                start=false;
                open++;
            }
            else{
                open--;
                if(open==0){
                    start=true;
                }
                else{
                    ans+=s[i];
                }
            }
            i++;
        }
        return ans;
    }
};