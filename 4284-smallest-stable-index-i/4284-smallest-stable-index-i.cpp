class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int>s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int mini=*s.begin();

            if(maxi-mini<=k) return i;

            auto it=s.find(nums[i]);
            s.erase(it);
        }
        return -1;
    }
};