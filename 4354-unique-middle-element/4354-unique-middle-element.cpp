class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n/2;i++) if(nums[i]==nums[n/2]) return false;
        for(int i=n/2+1;i<n;i++) if(nums[i]==nums[n/2]) return false;
        return true;
    }
};