class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mul=1;
        while(mul<=n){
            int number=k*mul;

            int index=upper_bound(nums.begin(),nums.end(),number)-nums.begin();
            if(index==0) return number;
            index--;
            if(nums[index]!=number) return number;

            mul++;
        }
        return mul*k;
    }
};