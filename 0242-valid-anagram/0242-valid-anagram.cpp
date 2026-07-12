class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        for(int i=0;i<n;i++){
            if(v[t[i]-'a']==0) return false;
            v[t[i]-'a']--;
        }
        return true;
    }
};