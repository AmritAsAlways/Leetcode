class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,maxi=1;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                i++;
                continue;
            }
            int prev=nums[i],j=i+1;
            while(j<n){
                if(nums[i+1]>nums[i] && nums[j]<=prev) break;
                if(nums[i+1]<nums[i] && nums[j]>=prev) break;
                prev=nums[j];
                j++;
            }
            maxi=max(j-i,maxi);
            i++;
        }
        return maxi;
    }
};