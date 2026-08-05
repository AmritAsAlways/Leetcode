class Solution {
public:
    int solve(vector<vector<pair<int,int>>>&adj,int source,int&n){
        vector<int>nodes(n+1,INT_MAX); //distance of all nodes from source when the signal is not transmitted yet
        vector<bool>visited(n+1,false);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        minheap.push({0,source});
        while(!minheap.empty()){
            pair<int,int>p=minheap.top();
            minheap.pop();
            int time=p.first,node=p.second;

            //first change the distance to that node
            if(!visited[node]) nodes[node]=time;
            visited[node]=true;

            //travserse the adj list of that node and put them in the minheap
            for(auto it:adj[node]){
                if(!visited[it.first]){
                    minheap.push({time+it.second,it.first});
                }
            }
        }

        //check for all the distance from the source node to all nodes
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,nodes[i]);
        }

        if(maxi==INT_MAX) return -1;
        return maxi;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++) adj[times[i][0]].push_back({times[i][1],times[i][2]});
        return solve(adj,k,n);
    }
};