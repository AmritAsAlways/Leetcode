class Solution {
public:
struct comparator{
    bool operator()(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b){
        if(a.first==b.first) return a.second.first>b.second.first;
        return a.first>b.first;
    }
};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comparator>minheap;
        for(int i=0;i<n;i++) minheap.push({nums1[i]+nums2[0],{i,0}});
        while(k>0){
            pair<int,pair<int,int>>mini=minheap.top();
            minheap.pop();
            int index1=mini.second.first,index2=mini.second.second;
            ans.push_back({nums1[index1],nums2[index2]});
            if(index2!=m-1) minheap.push({nums1[index1]+nums2[index2+1],{index1,index2+1}});
            k--;
        }
        return ans;
    };
};