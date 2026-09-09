class Solution {
public:
int find(char node,vector<char>&parent){
    char parentnode=parent[node-'a'];
    
    if(parentnode==node) return parentnode;

    return parent[node-'a']=find(parentnode,parent);
}
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<char>parent(26,'/');
        vector<long long>rank(26,1);
        for(int i=0;i<26;i++) parent[i]='a'+i;
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!') continue;
            char ch1=equations[i][0],ch2=equations[i][3];

            char parent1=find(ch1,parent),parent2=find(ch2,parent);

            if(rank[parent1-'a']>=rank[parent2-'a']){
                rank[parent1-'a']+=rank[parent2-'a'];
                parent[parent2-'a']=parent1;
            }
            else{
                rank[parent2-'a']+=rank[parent1-'a'];
                parent[parent1-'a']=parent2;
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='=') continue;
            char ch1=equations[i][0],ch2=equations[i][3];

            char parent1=find(ch1,parent),parent2=find(ch2,parent);
            if(parent2==parent1) return false;
        }
        return true;
    }
};