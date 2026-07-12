class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_map<int,int>um;
        stack<int>s;
        for(int i=m-1;i>=0;i--){
            while(!s.empty()){
                if(s.top()>nums2[i]){
                    um[nums2[i]]=s.top();
                    break;
                }
                s.pop();
            }
            if(s.empty()) um[nums2[i]]=-1;
            s.push(nums2[i]);
        }
        for(int i=0;i<n;i++) nums1[i]=um[nums1[i]];
        return nums1;
    }
};