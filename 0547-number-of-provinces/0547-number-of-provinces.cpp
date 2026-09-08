class Solution {
public:
int find(int node,vector<int>&parent){
    int parentnode=parent[node];

    if(parentnode==node) return node;

    return parent[node]=find(parentnode,parent);
}
void unionbyrank(vector<int>&rank,vector<int>&parent,int i,int j){
    int parent1=find(i,parent),parent2=find(j,parent);

    if(parent1==parent2) return;

    if(rank[parent1]>=rank[parent2]){
        rank[parent1]+=rank[parent2];
        parent[parent2]=parent1;
    }
    else{
        rank[parent2]+=rank[parent1];
        parent[parent1]=parent2;
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n+1,-1),rank(n+1,1);        
        for(int i=0;i<n+1;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            int node1=i+1;
            for(int j=0;j<n;j++){
                int node2=j+1;
                if(isConnected[i][j]==1) unionbyrank(rank,parent,node1,node2);
            }
        }
        unordered_set<int>us;
        for(int i=1;i<n+1;i++){
            int parentnode=find(i,parent);
            us.insert(parentnode);
        }
        return us.size();
    }
};