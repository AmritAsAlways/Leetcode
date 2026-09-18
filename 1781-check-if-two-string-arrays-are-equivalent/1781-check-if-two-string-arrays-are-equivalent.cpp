class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size(),m=word2.size();
        string first="",second="";
        for(int i=0;i<n;i++){
            for(int j=0;j<word1[i].size();j++) first+=word1[i][j];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<word2[i].size();j++) second+=word2[i][j];
        }
        if(first.size()!=second.size()) return false;
        n=first.size();
        for(int i=0;i<n;i++) if(first[i]!=second[i]) return false;
        return true;
    }
};