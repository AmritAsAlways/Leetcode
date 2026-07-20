class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        int rowahead=(k/n)%m,colahead=k%n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<rowahead<<" "<<colahead<<endl;
                ans[rowahead][colahead]=grid[i][j];
                colahead++;
                if(colahead==n){
                    colahead=0;
                    rowahead=(rowahead+1)%m;
                }
            }
        }
        return ans;
    }
};