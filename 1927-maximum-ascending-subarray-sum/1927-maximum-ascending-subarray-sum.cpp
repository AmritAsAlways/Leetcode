class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(),i=0,maxi=0;
        while(i<n){
            int sum=nums[i],j=i+1;
            while(j<n){
                if(nums[j]<=nums[j-1]) break;
                sum+=nums[j];
                j++;
            }
            i=j;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};