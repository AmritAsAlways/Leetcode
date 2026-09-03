class Solution {
public:
struct comparator{
    bool operator()(tuple<int,int,int>&a,tuple<int,int,int>&b){
        if(get<0>(a)==get<0>(b)) return get<1>(a)>get<1>(b);
        return get<0>(a)>get<0>(b);
    };
};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>ans;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,comparator>minheap;
        for(int i=0;i<n;i++) minheap.push({nums1[i]+nums2[0],i,0});
        while(k>0){
            k--;
            tuple<int,int,int>t=minheap.top();
            minheap.pop();

            ans.push_back({nums1[get<1>(t)],nums2[get<2>(t)]});

            if(get<2>(t)==m-1) continue;

            int idx1=get<1>(t),idx2=get<2>(t)+1;

            minheap.push({nums1[idx1]+nums2[idx2],idx1,idx2});
        }
        return ans;
    };
};