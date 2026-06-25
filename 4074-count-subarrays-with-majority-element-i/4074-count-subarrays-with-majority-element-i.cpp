class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),answer=0;
        for(int i=0;i<n;i++){
            int total=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) total++;
                if(total>(j-i+1)/2) answer++;
            }
        }
        return answer;
    }
};