class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(),i=0;
        bool drop=false;
        while(i<n){
            if(nums[(i+1)%n]<nums[i]){
                if(drop) return false;
                drop=true;
            }
            i++;
        }
        return true;
    }
};