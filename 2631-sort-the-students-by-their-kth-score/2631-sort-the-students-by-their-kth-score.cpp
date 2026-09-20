class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size(),n=score[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            v.push_back({score[i][k],i});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        vector<vector<int>>ans(m,vector<int>(n,0));
        int row=0;
        for(int i=0;i<m;i++){
            int r=v[i].second;

            for(int col=0;col<n;col++){
                ans[row][col]=score[r][col];
            }
            row++;
        }
        return ans;
    }
};