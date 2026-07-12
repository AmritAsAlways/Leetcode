class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),i=n-1,answer=0;
        while(i>=0){
            if(s[i]==' '){
                i--;
                continue;
            }

            int j=i;
            while(j>=0){
                if(s[j]==' ') break;
                j--;
            }
            answer=i-j;
            break;
        }
        return answer;
    }
};