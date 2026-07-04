class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n,{-1,-1});
        int answer=0,solution=0;
        for(int i=0;i<n;i++){
            int maxi=0,times=0;
            bool check=true;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j].first>maxi){
                    maxi=dp[j].first;
                    times=dp[j].second;
                    check=false;
                }
                else if(nums[i]>nums[j] && dp[j].first==maxi){
                    times+=dp[j].second;
                }
            }

            if(check){
                dp[i].first=1;
                dp[i].second=1;
            }
            else{
                dp[i].first=maxi+1;
                dp[i].second=times;
            }

            if(dp[i].first>answer){
                answer=dp[i].first;
                solution=dp[i].second;
            }
            else if(dp[i].first==answer){
                solution+=dp[i].second;
            }
        }
        return solution;
    }
};