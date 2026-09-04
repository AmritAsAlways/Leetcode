class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // int n=nums.size();
        // multiset<int>s;
        // for(int i=0;i<n;i++) s.insert(nums[i]);
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,nums[i]);
        //     int mini=*s.begin();

        //     if(maxi-mini<=k) return i;

        //     auto it=s.find(nums[i]);
        //     s.erase(it);
        // }
        // return -1;

        //other method
        int n=nums.size();
        vector<int>mini(n,INT_MAX);
        for(int i=n-1;i>=0;i--){
            mini[i]=nums[i];
            if(i!=n-1) mini[i]=min(mini[i],mini[i+1]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-mini[i]<=k) return i;
        }
        return -1;
    }
};