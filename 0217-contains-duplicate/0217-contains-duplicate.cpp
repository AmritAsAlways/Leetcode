class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size(),i=0;
        sort(nums.begin(),nums.end());
        while(i<n){
            int j=i+1;
            while(j<n){
                if(nums[j]!=nums[i]) break;
                return true;
                j++;
            }
            i=j;
        }
        return false;
    }
};