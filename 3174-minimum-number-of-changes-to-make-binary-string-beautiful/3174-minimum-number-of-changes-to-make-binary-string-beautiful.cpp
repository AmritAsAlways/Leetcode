class Solution {
public:
    int minChanges(string s) {
        int n=s.size(),i=0,answer=0;
        while(i<n){
            int j=i+1;
            while(j<n){
                if(s[j]!=s[i]) break;
                j++;
            }
            j--;
            int size=j-i+1;
            if(size%2==0){
                i=j+1;
            }
            else{
                answer++;
                i=j+2;
            }
        }
        return answer;
    }
};