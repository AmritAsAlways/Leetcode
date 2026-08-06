class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(isWater[i][j]==1){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
        int height=0,size=q.size();
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            size--;
            int row=p.first,col=p.second;
            isWater[row][col]=height;

            if(row+1<n && isWater[row+1][col]==0 && !visited[row+1][col]){
                visited[row+1][col]=true;
                q.push({row+1,col});
            }
            if(row-1>=0 && isWater[row-1][col]==0 && !visited[row-1][col]){
                visited[row-1][col]=true;
                q.push({row-1,col});
            }
            if(col+1<m && isWater[row][col+1]==0 && !visited[row][col+1]){
                visited[row][col+1]=true;
                q.push({row,col+1});
            }
            if(col-1>=0 && isWater[row][col-1]==0 && !visited[row][col-1]){
                visited[row][col-1]=true;
                q.push({row,col-1});
            }

            if(size==0){
                size=q.size();
                if(size!=0) height++;
            }

        }
        return isWater;
    }
};