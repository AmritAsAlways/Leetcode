class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        int answer=INT_MAX;
        sort(nums.begin(),nums.end());
        answer=min({answer,nums[n-3]-nums[1],nums[n-2]-nums[2],nums[n-1]-nums[3],nums[n-4]-nums[0],nums[n-3]-nums[1],nums[n-2]-nums[2]});
        return answer;
    }
};