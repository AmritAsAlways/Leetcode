class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long answer=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(nums[i],maxi);
        int l=0,r=0,count=0;
        while(r<n){
            if(nums[r]==maxi) count++;
            while(count==k){
                answer+=n-r;
                if(nums[l]==maxi) count--;
                l++;
            }
            r++;
        }
        return answer;
    }
};