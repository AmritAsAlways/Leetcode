class Solution {
public:
int find(vector<int>&parent,int root){ //find by path compresion
    int rootparent=parent[root];

    if(parent[root]==root) return root;
    return parent[root]=find(parent,rootparent);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,-1),rank(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
        //this is the union part code
        for(int i=0;i<n;i++){
            int parent1=find(parent,edges[i][0]);
            int parent2=find(parent,edges[i][1]);

            if(parent1==parent2){//means that both nodes are the children of the same root
            //so there should be not edges/connection/union between them as it is a property of the tree
            return edges[i];
            }

            if(rank[parent1]>rank[parent2]){
                rank[parent1]+=rank[parent2];
                parent[parent2]=parent1;
            }
            else if(rank[parent1]<rank[parent2]){
                rank[parent2]+=rank[parent1];
                parent[parent1]=parent2;
            }
            else{
                rank[parent1]+=rank[parent2];
                parent[parent2]=parent1;
            }
        }
        return {};
    }
};