class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int distance=0,size=q.size();
        if(q.size()==0 || q.size()==n*n) return -1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            size--;
            int row=p.first,col=p.second;
            grid[row][col]=distance;

            if(row+1<n && grid[row+1][col]==0 && !visited[row+1][col]){
                visited[row+1][col]=true;
                q.push({row+1,col});
            }
            if(row-1>=0 && grid[row-1][col]==0 && !visited[row-1][col]){
                visited[row-1][col]=true;
                q.push({row-1,col});
            }
            if(col+1<n && grid[row][col+1]==0 && !visited[row][col+1]){
                visited[row][col+1]=true;
                q.push({row,col+1});
            }
            if(col-1>=0 && grid[row][col-1]==0 && !visited[row][col-1]){
                visited[row][col-1]=true;
                q.push({row,col-1});
            }

            if(size==0){
                size=q.size();
                if(size!=0) distance++;
            }


        }
        return distance;
    }
};