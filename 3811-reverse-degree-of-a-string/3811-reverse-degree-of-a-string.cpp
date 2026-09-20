class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size(),answer=0;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            idx=26-idx;
            answer+=(i+1)*idx;
        }
        return answer;
    }
};