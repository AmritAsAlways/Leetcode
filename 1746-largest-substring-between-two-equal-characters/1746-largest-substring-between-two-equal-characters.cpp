class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        vector<int>v(26,-1);
        int answer=-1;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']!=-1){
                answer=max(answer,i-v[s[i]-'a']-1);
            }
            else v[s[i]-'a']=i;
        }
        return answer;
    }
};