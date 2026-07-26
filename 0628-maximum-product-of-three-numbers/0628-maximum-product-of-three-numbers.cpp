class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        //product of the maximum 3 numbers
        maxi=max(nums[n-1]*nums[n-2]*nums[n-3],maxi);
        //product of the minimum 3 numbers
        maxi=max(maxi,nums[0]*nums[1]*nums[2]);
        //product of the minimum 2 numbers and 1 maximum number
        maxi=max(maxi,nums[0]*nums[1]*nums[n-1]);
        return maxi;
    }
};