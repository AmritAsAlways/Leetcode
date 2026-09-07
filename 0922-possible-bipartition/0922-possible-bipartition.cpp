class Solution {
public:
bool solve(vector<vector<int>>&adj,vector<int>&visited,int node){
    queue<pair<int,bool>>q;
    q.push({node,true});
    while(!q.empty()){
        pair<int,bool>p=q.front();
        q.pop();
        int person=p.first;
        bool color=p.second;

        int colorvalue= (color==true) ? 1 : 2;

        if(visited[person]!=-1 && visited[person]!=colorvalue) return false;
        visited[person]=colorvalue;

        for(int i=0;i<adj[person].size();i++){
            if(visited[adj[person][i]]==-1) q.push({adj[person][i],!color});
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m=dislikes.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int person1=dislikes[i][0],person2=dislikes[i][1];
            adj[person1].push_back(person2);
            adj[person2].push_back(person1);
        }
        vector<int>visited(n+1,-1);
        for(int i=1;i<n+1;i++){
            if(visited[i]==-1){
                if(!solve(adj,visited,i)) return false;
            }
        }
        return true;
    }
};