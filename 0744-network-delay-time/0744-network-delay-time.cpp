class Solution {
public:
int solve(vector<vector<pair<int,int>>>&adj,int&n,int&k){
    vector<int>dist(n+1,INT_MAX);
    vector<bool>visited(n+1,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
    minheap.push({0,k});
    while(!minheap.empty()){
        pair<int,int>p=minheap.top();
        int node=p.second,distance=p.first;
        visited[node]=true;
        minheap.pop();

        if(dist[node]>distance) dist[node]=distance;

        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i].first]==false) minheap.push({distance+adj[node][i].second,adj[node][i].first});
        }
    }
    int mintime=INT_MIN;
    for(int i=1;i<n+1;i++){
        if(dist[i]==INT_MAX) return -1;
        mintime=max(mintime,dist[i]);
    }
    return mintime;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>v(n+1);
        int m=times.size();
        for(int i=0;i<m;i++){
            int source=times[i][0],target=times[i][1],weight=times[i][2];
            v[source].push_back({target,weight});
        }
        return solve(v,n,k);
    }
};