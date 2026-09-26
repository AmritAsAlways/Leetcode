class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_set<int>first,second;
        for(int i=0;i<n;i++) first.insert(nums1[i]);
        for(int i=0;i<m;i++) second.insert(nums2[i]);
        vector<int>one,two;
        for(auto&it:first){
            if(second.find(it)==second.end()) one.push_back(it);
        }
        for(auto&it:second){
            if(first.find(it)==first.end()) two.push_back(it);
        }
        return {one,two};
    }
};