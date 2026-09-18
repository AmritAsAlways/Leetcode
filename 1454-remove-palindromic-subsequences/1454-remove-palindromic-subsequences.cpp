class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size(),i=0,j=n-1;
        int answer=1;
        while(i<=j){
            if(s[i]==s[j]){
                s[i]='*';
                s[j]='*';
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        j=n-1;
        bool check=true;
        while(i<=j){
            if(s[i]=='*'){
                i++;
                continue;
            }
            if(s[j]=='*'){
                continue;
            }

            if(s[i]==s[j]){
                s[i]='*';
                s[j]='*';
                i++;
                j--;
                check=false;
            }
            else{
                j--;
            }
        }
        if(!check) answer++;
        return answer;
    }
};