class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++) maxheap.push(nums[i]);
        while(k>1){
            int maximum=maxheap.top();
            maxheap.pop();

            k--;
        }
        return maxheap.top();
    }
};