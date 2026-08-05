class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m=edges.size();
        vector<vector<long long>>v(n,vector<long long>(n,1e4+1));
        for(int i=0;i<n;i++) v[i][i]=0;
        for(int i=0;i<m;i++){
            v[edges[i][0]][edges[i][1]]=edges[i][2];
            v[edges[i][1]][edges[i][0]]=edges[i][2];
        }

        //cover all the edges via this vertices
        for(int i=0;i<n;i++){
            //all possible edges in the graph
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    long long dist=v[a][i]+v[i][b];
                    if(dist<v[a][b]) v[a][b]=dist;
                }
            }

        }
        

        int answercity=-1;
        long long smallestcity=LLONG_MAX;
        for(int i=0;i<n;i++){
            int city=0;
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
                if(v[i][j]<=distanceThreshold) city++;
            }
            cout<<endl;
            cout<<city<<" "<<smallestcity<<" "<<i<<endl;

            if(city<=smallestcity){
                smallestcity=city;
                answercity=i;
            }


        }

        return answercity;
    }
};