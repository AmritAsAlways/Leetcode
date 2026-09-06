class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1,end=INT_MIN; //starting divisor is 1 and ending divisor is 
        for(int i=0;i<n;i++) end=max(end,nums[i]);
        int answer=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;

            long long result=0;

            for(int i=0;i<n;i++){
                double x=(double)nums[i]/(double)mid;
                result+=ceil(x);
            }

            if(result<=1LL*threshold){
                answer=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return answer;
    }
};