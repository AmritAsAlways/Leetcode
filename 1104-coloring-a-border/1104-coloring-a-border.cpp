class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size(),n=grid[0].size();
        int tempcolor=grid[row][col];
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>cantake(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=tempcolor) continue;
                if(i+1<m) cantake[i+1][j]++;
                if(i-1>=0) cantake[i-1][j]++;
                if(j+1<n) cantake[i][j+1]++;
                if(j-1>=0) cantake[i][j-1]++;
            }
        }
        visited[row][col]=true;
        while(!q.empty()){
            pair<int,int>p=q.front();
            int r=p.first,c=p.second;
            grid[r][c]=color;
            q.pop();

            if(r+1<m && visited[r+1][c]==false && grid[r+1][c]==tempcolor){
                visited[r+1][c]=true;
                q.push({r+1,c});
            }
            if(r-1>=0 && visited[r-1][c]==false && grid[r-1][c]==tempcolor){
                visited[r-1][c]=true;
                q.push({r-1,c});
            }
            if(c+1<n && visited[r][c+1]==false && grid[r][c+1]==tempcolor){
                visited[r][c+1]=true;
                q.push({r,c+1});
            }
            if(c-1>=0 && visited[r][c-1]==false && grid[r][c-1]==tempcolor){
                visited[r][c-1]=true;
                q.push({r,c-1});
            }
        }
        cout<<grid[1][1]<<" "<<visited[1][1]<<" "<<cantake[1][1]<<" "<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==color && visited[i][j]==true && cantake[i][j]==4){
                    grid[i][j]=tempcolor;
                    cout<<i<<" "<<j<<endl;
                }
            }
        }

        return grid;
    }
};