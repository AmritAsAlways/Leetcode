class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),depth=0,answer=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                answer=max(answer,depth);
            }
            else if(s[i]==')') depth--;
        }
        return answer;
    }
};