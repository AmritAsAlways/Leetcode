class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m) return false;
        unordered_map<int,int>first,second;
        for(int i=0;i<n;i++){
            if(first.count(s[i])==0 && second.count(t[i])==1) return false;
            if(first.count(s[i])==1 && second.count(t[i])==0) return false;

            if(first.count(s[i])==0 && second.count(t[i])==0){
                first[s[i]]=t[i];
                second[t[i]]=s[i];
            }
            else if(first[s[i]]!=t[i] || second[t[i]]!=s[i]) return false;
        }
        return true;
    }
};