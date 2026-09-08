class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int orange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
                if(grid[i][j]==1) orange++;
            }
        }
        int size=q.size(),time=0,freshorange=0;
        while(!q.empty()){
            pair<int,int>p=q.front();
            int row=p.first,col=p.second;
            size--;
            q.pop();

            if(row+1<m && grid[row+1][col]==1 && visited[row+1][col]==false){
                visited[row+1][col]=true;
                grid[row+1][col]=2;
                freshorange++;
                q.push({row+1,col});
            }
            if(row-1>=0 && grid[row-1][col]==1 && visited[row-1][col]==false){
                visited[row-1][col]=true;
                grid[row-1][col]=2;
                freshorange++;
                q.push({row-1,col});
            }
            if(col+1<n && grid[row][col+1]==1 && visited[row][col+1]==false){
                visited[row][col+1]=true;
                grid[row][col+1]=2;
                freshorange++;
                q.push({row,col+1});
            }
            if(col-1>=0 && grid[row][col-1]==1 && visited[row][col-1]==false){
                visited[row][col-1]=true;
                grid[row][col-1]=2;
                q.push({row,col-1});
                freshorange++;
            }

            if(size==0){
                size=q.size();
                time++;
            }
        }
        if(orange==0) return 0;
        if(orange!=freshorange) return -1;
        return time-1;
    }
};