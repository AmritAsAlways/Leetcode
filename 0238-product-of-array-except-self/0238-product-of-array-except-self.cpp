class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),total=1,zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) total*=nums[i];
            else zero++;
        }
        for(int i=0;i<n;i++){
            if(zero>1){
                nums[i]=0;
                continue;
            }

            if(nums[i]!=0){
                if(zero==0) nums[i]=total/nums[i];
                else nums[i]=0;
            }
            else{
                nums[i]=total;
            }
        }
        return nums;
    }
};