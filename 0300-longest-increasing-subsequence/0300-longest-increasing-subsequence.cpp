class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it==v.end()){
                v.push_back(nums[i]);
                continue;
            }

            int idx=it-v.begin();
            v[idx]=nums[i];
        }
        return v.size();
    }
};