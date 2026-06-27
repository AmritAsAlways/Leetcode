class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long answer=0,i=0,index=0;
        while(i<n){
            if(s[i]=='0'){
                answer+=i-index;
                index++;
            }
            i++;
        }
        return answer;
    }
};