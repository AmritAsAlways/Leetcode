class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1,end=INT_MAX; //starting divisor is 1 and ending divisor is INT_MAX
        int answer=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;

            double result=0;

            for(int i=0;i<n;i++){
                double x=(double)nums[i]/(double)mid;
                result+=ceil(x);
            }

            if(result<=(double)threshold){
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