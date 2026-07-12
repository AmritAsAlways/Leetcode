class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        int row=2;
        ans[0]={1};
        while(row<=numRows){
            vector<int>v;
            v.push_back(1);
            int j=1;
            while(j<ans[row-2].size()){
                v.push_back(ans[row-2][j]+ans[row-2][j-1]);
                j++;
            }
            v.push_back(1);
            ans[row-1]=v;
            row++;
        }
        return ans;
    }
};