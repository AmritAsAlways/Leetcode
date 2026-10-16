class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size(),sum=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minheap;
        for(int i=1;i<m;i++) sum+=mat[i][0];
        for(int i=0;i<n;i++){
            vector<int>v;
            v.push_back(sum+mat[0][i]);
            v.push_back(i);
            for(int j=0;j<m-1;j++) v.push_back(0);
            minheap.push(v);
        }
        set<vector<int>>s;
        while(k>1){
            vector<int>v=minheap.top();
            minheap.pop();
            int m=v.size();
            for(int i=2;i<m;i++){
                vector<int>temp=v;
                if(temp[i]+1<n){
                    temp[0]-=mat[i-1][temp[i]];
                    temp[0]+=mat[i-1][temp[i]+1];
                    temp[i]++;
                    if(s.find(temp)==s.end()){
                        minheap.push(temp);
                        s.insert(temp);
                    }
                }
            }
            k--;
        }
        return minheap.top()[0];
    }
};