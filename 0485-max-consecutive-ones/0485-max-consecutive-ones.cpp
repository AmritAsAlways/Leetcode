class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),i=0,maxi=0;
        while(i<n){
            if(nums[i]==0){
                i++;
                continue;
            }
            int j=i+1;
            while(j<n){
                if(nums[j]==0) break;
                j++;
            }
            maxi=max(maxi,j-i);
            i=j;
        }
        return maxi;
    }
};