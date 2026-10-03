class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size(),i=0;
        double sum=0,avg=INT_MIN,divide=k;
        while(i<k){
            sum+=nums[i];
            i++;
        }
        avg=max(avg,sum/divide);
        while(i<n){
            sum+=nums[i];
            sum-=nums[i-k];
            avg=max(avg,sum/divide);
            i++;
        }
        return avg;
    }
};