class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),totaloperation=m*n;
        k%=totaloperation;
        int rowahead=k/n,colahead=(k%n);
        cout<<rowahead<<" "<<colahead<<endl;
        vector<vector<int>>v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int col=j+colahead,row=i+rowahead;
                if(col>=n) row++;
                v[row%m][col%n]=grid[i][j];
            }
        }
        return v;
    }
};