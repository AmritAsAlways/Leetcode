class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            long long right=LLONG_MIN,left=LLONG_MIN;
            if(mid+1<n) right=nums[mid+1];
            if(mid-1>=0) left=nums[mid-1];


            if(1LL*nums[mid]>right && 1LL*nums[mid]>left) return mid;

            if(right>=left){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};