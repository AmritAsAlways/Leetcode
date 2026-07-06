class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long j=n-1,maxi=LLONG_MIN,answer=LLONG_MIN,i=n-1-k;
        while(i>=0){
            maxi=max(maxi,1LL*nums[j]);
            answer=max(answer,maxi+1LL*nums[i]);
            i--;
            j--;
        }
        return answer;
    }
};