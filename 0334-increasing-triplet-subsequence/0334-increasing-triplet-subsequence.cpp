class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightmaxi(n,INT_MIN),leftmini(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(i==0) continue;
            leftmini[i]=min(leftmini[i-1],nums[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) continue;
            rightmaxi[i]=max(rightmaxi[i+1],nums[i+1]);
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>leftmini[i] && rightmaxi[i]>nums[i]) return true;
        }
        return false;
    }
};