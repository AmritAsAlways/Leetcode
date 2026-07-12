class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size(),i=0;
        if(n==1) return true;
        while(i<n-1){
            if(nums[i+1]!=nums[i]) break;
            i++;
        }
        bool greater=true;
        if(i+1<n && nums[i+1]<nums[i]) greater=false;
        while(i<n-1){
            if(greater && nums[i+1]<nums[i]) return false;
            if(!greater && nums[i+1]>nums[i]) return false;
            i++;
        }
        return true;
    }
};