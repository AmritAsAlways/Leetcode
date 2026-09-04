class Solution {
public:
    string customSortString(string order, string s) {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        string ans="";
        for(int i=0;i<order.size();i++){
            int idx=order[i]-'a';
            while(v[idx]>0){
                char ch=order[i];
                ans+=ch;
                v[idx]--;
            }
        }
        for(int i=0;i<26;i++){
            while(v[i]>0){
                char ch='a'+i;
                ans+=ch;
                v[i]--;
            }
        }
        return ans;
    }
};