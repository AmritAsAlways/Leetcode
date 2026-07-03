class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size(),i=0;
        vector<string>v;
        while(i<n){
            string s=to_string(nums[i]);
            int end=nums[i];
            int j=i+1;
            while(j<n){
                if(nums[j]>end+1) break;
                end=nums[j];
                j++;
            }
            if(end!=nums[i]) s+="->";
            if(end!=nums[i]) s+=to_string(end);
            v.push_back(s);
            i=j;
        }
        return v;
    }
};