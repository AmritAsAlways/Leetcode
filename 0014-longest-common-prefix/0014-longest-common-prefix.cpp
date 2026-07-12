class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(),i=0;
        string ans="";
        while(i<strs[0].size()){
            bool check=true;
            for(int j=0;j<n;j++){
                if(strs[j][i]!=strs[0][i]){
                    check=false;
                    break;
                }
            }
            if(check) ans+=strs[0][i];
            else break;
            i++;
        }
        return ans;
    }
};