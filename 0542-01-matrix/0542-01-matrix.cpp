class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int distance=0,size=q.size();
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            size--;
            int row=p.first,col=p.second;
            mat[row][col]=distance;

            if(row+1<m && mat[row+1][col]==1 && !visited[row+1][col]){
                visited[row+1][col]=true;
                q.push({row+1,col});
            }
            if(row-1>=0 && mat[row-1][col]==1 && !visited[row-1][col]){
                visited[row-1][col]=true;
                q.push({row-1,col});
            }
            if(col+1<n && mat[row][col+1]==1 && !visited[row][col+1]){
                visited[row][col+1]=true;
                q.push({row,col+1});
            }
            if(col-1>=0 && mat[row][col-1]==1 && !visited[row][col-1]){
                visited[row][col-1]=true;
                q.push({row,col-1});
            }

            if(size==0){
                size=q.size();
                if(size!=0) distance++;
            }


        }
        return mat;
    }
};