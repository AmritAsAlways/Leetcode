class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size(),answer=0;
        for(int i=0;i<n-1;i++){
            answer+=abs(s[i]-s[(i+1)%n]);
        }
        return answer;
    }
};