class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        int visitedrooms=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int room=q.front();
            visitedrooms++;
            q.pop();

            int m=rooms[room].size();
            for(int i=0;i<m;i++){
                if(visited[rooms[room][i]]==false){
                    q.push({rooms[room][i]});
                    visited[rooms[room][i]]=true;
                }
            }
        }
        return visitedrooms==n ? true : false;
    }
};