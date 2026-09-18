class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size(),idx1=-1,idx2=-1;
        for(int i=0;i<n;i++){
            if(s[i]==goal[i]) continue;

            if(idx1==-1) idx1=i;
            else if(idx2==-1) idx2=i;
            else return false;
        }
        if(idx1==idx2 && idx1==-1){ //means there is no position in strings where char. are not equal
            vector<int>v(26,0);
            for(int i=0;i<n;i++){
                v[s[i]-'a']++;
                if(v[s[i]-'a']==2) return true;
            }
            return false;
        }

        if(idx1==-1 || idx2==-1) return false;
        if(s[idx1]!=goal[idx2] || goal[idx1]!=s[idx2]) return false;
        return true;
    }
};