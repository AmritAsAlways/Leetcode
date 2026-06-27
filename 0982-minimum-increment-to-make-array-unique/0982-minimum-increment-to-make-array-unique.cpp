class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int answer=0,i=1;
        while(i<n){
            if(nums[i]>nums[i-1]){
                i++;
                continue;
            }
            answer+=abs(nums[i-1]-nums[i])+1;
            nums[i]=nums[i-1]+1;
            i++;
        }
        return answer;
    }
};