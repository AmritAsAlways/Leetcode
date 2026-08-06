class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            adj[flights[i][0]].push_back({flights[i][2],flights[i][1]});
        }

        vector<int>dist(n,INT_MAX);

        int loop=n-1;
        if(k+1<n-1) loop=k+1;
        dist[src]=0;
        while(loop--){
            vector<int>temp=dist;

            // for(int i=0;i<n;i++){
            //     if(dist[i]==INT_MAX) continue;
            //     cout<<i<<"->";
            //     for(int j=0;j<adj[i].size();j++){
            //         cout<<adj[i][j].second<<" "<<dist[i]<<" "<<adj[i][j].first<<"#";
            //         if(dist[i]+adj[i][j].first<dist[adj[i][j].second]){
            //             dist[adj[i][j].second]=dist[i]+adj[i][j].first;
            //         }
            //     }
            //     cout<<endl;
            // }

            for(auto&it:flights){
                int u=it[0],v=it[1],w=it[2];
                if(dist[u]!=INT_MAX && dist[u]+w<temp[v]) temp[v]=dist[u]+w;
            }

            dist=temp;
            
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};