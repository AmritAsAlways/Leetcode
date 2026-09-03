class Solution {
public:
struct comparator{
    bool operator()(tuple<int,int,int>&a,tuple<int,int,int>&b){
        if(get<0>(a)==get<0>(b)) return get<1>(a)>get<1>(b);
        return get<0>(a)>get<0>(b);;
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,comparator>minheap;
        for(int i=0;i<n;i++) minheap.push({matrix[i][0],i,0});
        int kthvalue=-1;
        while(k--){
            tuple<int,int,int>t=minheap.top();
            kthvalue=get<0>(t);
            minheap.pop();

            if(get<2>(t)==n-1) continue;

            int row=get<1>(t),col=get<2>(t)+1;
            minheap.push({matrix[row][col],row,col});
        }
        return kthvalue;
    }
};