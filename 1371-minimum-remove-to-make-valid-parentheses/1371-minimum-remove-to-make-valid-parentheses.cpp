class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')') continue;

            if(dq.empty()){
                dq.push_back(i);
                continue;
            }

            if(s[i]==')' && s[dq.back()]!=s[i]){
                dq.pop_back();
            }
            else{
                dq.push_back(i);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')') ans+=s[i];
            else{
                if(!dq.empty() && dq.front()==i){
                    dq.pop_front();
                }
                else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};