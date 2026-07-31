class Solution {
public:
struct comparator{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size(),i=0;
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>minheap;
        int size=0;
        while(i<n){
            int j=i;
            while(j<n){
                if(nums[j]!=nums[i]) break;
                j++;
            }
            if(size==k){
                if(minheap.top().second<j-i){
                    minheap.pop();
                    minheap.push({nums[i],j-i});
                }
            }
            else{
                minheap.push({nums[i],j-i});
                size++;
            }
            i=j;
        }
        vector<int>v;
        while(!minheap.empty()){
            v.push_back(minheap.top().first);
            minheap.pop();
        }
        return v;
    }
};