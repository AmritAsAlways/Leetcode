class Solution {
public:
    string removeStars(string s) {
        int n=s.size(),star=0,j=n-1;
        string ans="";
        while(j>=0){
            if(s[j]=='*'){
                s[j]='?';
                star++;
                j--;
                continue;
            }

            if(star>0){
                s[j]='?';
                star--;
            }
            j--;
        }
        for(int i=0;i<n;i++){
            if(s[i]!='?') ans+=s[i];
        }
        return ans;
    }
};