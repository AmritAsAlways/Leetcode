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
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>minheap;
        int size=0;
        unordered_map<int,int>um;
        while(i<n){
            um[nums[i]]++;
            i++;
        }
        for(auto&it:um){
            if(size==k){
                if(minheap.top().second<it.second){
                    minheap.pop();
                    minheap.push({it.first,it.second});
                }
            }
            else{
                minheap.push({it.first,it.second});
                size++;
            }
        }

        vector<int>v;
        while(!minheap.empty()){
            v.push_back(minheap.top().first);
            minheap.pop();
        }
        return v;
    }
};