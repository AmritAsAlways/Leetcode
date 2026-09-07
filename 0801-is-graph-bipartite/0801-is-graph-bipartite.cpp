class Solution {
public:
bool solve(vector<vector<int>>&graph,vector<int>&visited,int source){
    queue<pair<int,bool>>q;
        q.push({source,true});
        while(!q.empty()){
            int node=q.front().first;
            bool color=q.front().second;
            int colorvalue= (color==true) ? 1 : 2;
            if(visited[node]!=-1 && visited[node]!=colorvalue) return false;
            else{
                visited[node]=colorvalue;
            }
            color=!color;
            q.pop();

            for(int i=0;i<graph[node].size();i++){
                if(visited[graph[node][i]]==-1) q.push({graph[node][i],color});
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!solve(graph,visited,i)) return false;
            }
        }
        return true;
    }
};