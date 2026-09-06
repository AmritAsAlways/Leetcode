class Solution {
public:
void solution(vector<vector<char>>&board,vector<vector<bool>>&visited,int row,int col){
    int m=board.size(),n=visited[0].size();

    queue<pair<int,int>>q;
    q.push({row,col});
    visited[row][col]=true;
    while(!q.empty()){
        pair<int,int>p=q.front();
        int r=p.first,c=p.second;
        q.pop();

        if(r+1<m && board[r+1][c]=='O' && visited[r+1][c]==false){
            visited[r+1][c]=true;
            q.push({r+1,c});
        }
        if(r-1>=0 && board[r-1][c]=='O' && visited[r-1][c]==false){
            visited[r-1][c]=true;
            q.push({r-1,c});
        }
        if(c+1<n && board[r][c+1]=='O' && visited[r][c+1]==false){
            visited[r][c+1]=true;
            q.push({r,c+1});
        }
        if(c-1>=0 && board[r][c-1]=='O' && visited[r][c-1]==false){
            visited[r][c-1]=true;
            q.push({r,c-1});
        }

    }

}
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O' && visited[0][i]==false){
                solution(board,visited,0,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O' && visited[m-1][i]==false){
                solution(board,visited,m-1,i);
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O' && visited[i][0]==false){
                solution(board,visited,i,0);
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][n-1]=='O' && visited[i][n-1]==false){
                solution(board,visited,i,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==false) board[i][j]='X';
            }
        }
    }
};