class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size(),even=0,odd=0,smallest=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) even++;
            else odd++;
            smallest=min(smallest,nums1[i]);
        }
        if(smallest%2!=0) return true;
        if(odd==0) return true;
        return false;
    }
};