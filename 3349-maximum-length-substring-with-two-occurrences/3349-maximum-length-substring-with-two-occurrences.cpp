class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size(),i=0,j=0,answer=0;
        vector<int>v(26,0);
        while(j<n){
            v[s[j]-'a']++;
            while(v[s[j]-'a']>2){
                v[s[i]-'a']--;
                i++;
            }
            answer=max(answer,j-i+1);
            j++;
        }
        return answer;
    }
};