class Solution {
public:
int find(int node,vector<int>&parent){
    int parentnode=parent[node];

    if(parentnode==node) return node;

    return parent[node]=find(parentnode,parent);
}
void unionbyrank(int node1,int node2,vector<int>&parent,vector<int>&rank,int&extraconnection){
    int parent1=find(node1,parent),parent2=find(node2,parent);

    if(parent1==parent2){
        extraconnection++;
        return;
    }

    if(rank[parent1]>=rank[parent2]){
        rank[parent1]+=rank[parent2];
        parent[parent2]=parent1;
    }
    else{
        rank[parent2]+=rank[parent1];
        parent[parent1]=parent2;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<int>parent(n,-1),rank(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        int extraconnection=0;
        for(int i=0;i<m;i++){
            int node1=connections[i][0],node2=connections[i][1];
            unionbyrank(node1,node2,parent,rank,extraconnection);
        }
        unordered_set<int>us;
        for(int i=0;i<n;i++){
            int parentnode=find(i,parent);
            us.insert(parentnode);
        }
        if(us.size()-1>extraconnection) return -1;
        return us.size()-1;
    }
};