class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //binary search solution
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            int index=it-v.begin();

            if(it==v.end()){
                v.push_back(nums[i]);
                continue;
            }

            v[index]=nums[i];
        }
        return v.size();
    }
};