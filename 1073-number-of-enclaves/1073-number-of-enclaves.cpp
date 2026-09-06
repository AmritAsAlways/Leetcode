class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){ //for the first row
            if(grid[0][i]==1 && visited[0][i]==false){
                q.push({0,i});
                visited[0][i]=true;
            }
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]==1 && visited[m-1][i]==false){
                visited[m-1][i]=true;
                q.push({m-1,i});
            }
        }
        for(int i=1;i<m-1;i++){
            if(grid[i][0]==1 && visited[i][0]==false){
                visited[i][0]=true;
                q.push({i,0});
            }
        }
        for(int i=1;i<m-1;i++){
            if(grid[i][n-1]==1 && visited[i][n-1]==false){
                visited[i][n-1]=true;
                q.push({i,n-1});
            }
        }

        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int row=p.first,col=p.second;

            if(row+1<m && grid[row+1][col]==1 && visited[row+1][col]==false){
                visited[row+1][col]=true;
                q.push({row+1,col});
            }
            if(row-1>=0 && grid[row-1][col]==1 && visited[row-1][col]==false){
                visited[row-1][col]=true;
                q.push({row-1,col});
            }
            if(col+1<n && grid[row][col+1]==1 && visited[row][col+1]==false){
                visited[row][col+1]=true;
                q.push({row,col+1});
            }
            if(col-1>=0 && grid[row][col-1]==1 && visited[row][col-1]==false){
                visited[row][col-1]=true;
                q.push({row,col-1});
            }
        }

        int totalones=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==false) totalones++;
            }
        }

        return totalones;
    }
};