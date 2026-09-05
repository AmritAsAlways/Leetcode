class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>v(n,-1);
        for(int i=n-1;i>=0;i--){
            v[i]=nums[i];
            if(i!=n-1) v[i]=min(v[i],v[i+1]);
        }
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(maxi-v[i]<=k) return i;
        }
        return -1;
    }
};