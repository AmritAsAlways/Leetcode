class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>v;
        unordered_set<int>us;
        for(int i=0;i<n;i++) us.insert(nums1[i]);
        for(int i=0;i<m;i++){
            if(us.count(nums2[i])){
                v.push_back(nums2[i]);
                us.erase(nums2[i]);
            }
        }
        return v;
    }
};