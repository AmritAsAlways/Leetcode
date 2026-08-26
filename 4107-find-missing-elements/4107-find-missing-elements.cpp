class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int num=nums[0]+1,i=1;
        vector<int>v;
        while(num<nums[n-1]){
            if(nums[i]==num){
                i++;
            }
            else v.push_back(num);
            num++;
        }
        return v;
    }
};