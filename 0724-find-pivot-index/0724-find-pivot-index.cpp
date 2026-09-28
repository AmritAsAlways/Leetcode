class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int leftsum=0,maxi=0;
        for(int i=0;i<n;i++) maxi+=nums[i];
        for(int i=0;i<n;i++){
            if(leftsum==maxi-nums[i]-leftsum) return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};