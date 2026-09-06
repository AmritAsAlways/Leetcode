class Solution {
public:
void solve(vector<vector<int>>&grid,vector<vector<bool>>&visited,int row,int col,int&island){
    int m=grid.size(),n=grid[0].size();

    queue<pair<int,int>>q;
    q.push({row,col});
    visited[row][col]=true;
    bool boundary=false;
    while(!q.empty()){
        pair<int,int>p=q.front();
        int r=p.first,c=p.second;
        if(r==0 || r==m-1 || c==0 || c==n-1) boundary=true;
        q.pop();

        if(r+1<m && grid[r+1][c]==0 && visited[r+1][c]==false){
            visited[r+1][c]=true;
            q.push({r+1,c});
        }
        if(r-1>=0 && grid[r-1][c]==0 && visited[r-1][c]==false){
            visited[r-1][c]=true;
            q.push({r-1,c});
        }
        if(c+1<n && grid[r][c+1]==0 && visited[r][c+1]==false){
            visited[r][c+1]=true;
            q.push({r,c+1});
        }
        if(c-1>=0 && grid[r][c-1]==0 && visited[r][c-1]==false){
            visited[r][c-1]=true;
            q.push({r,c-1});
        }
    }
    if(boundary) island++;
}
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int totalislands=0,notclosedislands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && visited[i][j]==false){
                    totalislands++;
                    solve(grid,visited,i,j,notclosedislands);
                }
            }
        }
        return totalislands-notclosedislands;
    }
};