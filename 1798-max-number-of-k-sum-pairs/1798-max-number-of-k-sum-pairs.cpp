class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size(),answer=0;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];

            if(sum==k){
                i++;
                j--;
                answer++;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return answer;
    }
};