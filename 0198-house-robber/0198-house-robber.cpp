class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[n-1]=nums[n-1];
        if(n-2>=0) dp[n-2]=nums[n-2];
        for(int i=n-3;i>=0;i--){
            dp[i]=nums[i];
            int answer=0;
            for(int j=i+2;j<n;j++){
                answer=max(answer,dp[j]);
            }
            dp[i]+=answer;
        }
        int solution=0;
        for(int i=0;i<n;i++) solution=max(solution,dp[i]);
        return solution;
    }
};