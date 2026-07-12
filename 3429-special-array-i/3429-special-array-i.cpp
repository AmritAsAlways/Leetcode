class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size(),i=0;
        if(n==1) return true;
        bool even=true;
        if(nums[0]%2) even=false;
        while(i<n){
            if(even && nums[i]%2!=0) return false;
            if(!even && nums[i]%2==0) return false;
            even=!even;
            i++;
        }
        return true;
    }
};