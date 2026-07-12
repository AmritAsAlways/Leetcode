class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>v(n,vector<int>(26,0));
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++) v[i][words[i][j]-'a']++;
        }
        for(int i=0;i<26;i++){
            int value=v[0][i];
            for(int j=0;j<n;j++) value=min(value,v[j][i]);
            string s="a";
            s[0]='a'+i;
            while(value>0){
                ans.push_back(s);
                value--;
            }
        }
        return ans;
    }
};