class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size(),i=n-1;
        sort(nums.begin(),nums.end());
        long long answer=0;
        while(k>0){
            if(mul<=0){
                answer+=nums[i];
            }
            else{
                answer+=1LL*nums[i]*mul;
            }
            mul--;
            k--;
            i--;
        }
        return answer;
    }
};