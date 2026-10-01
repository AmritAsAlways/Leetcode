class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),i=0,j=0;
        while(j<n){
            if(nums[j]==0){
                j++;
                continue;
            }
            nums[i]=nums[j];
            j++;
            i++;
        }
        while(i<n){
            nums[i]=0;
            i++;
        }
    }
};