class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,answer=0;
        for(int i=0;i<n;i++){
            int largest=INT_MIN,smallest=INT_MAX,num=nums[i];
            while(nums[i]>0){
                int r=nums[i]%10;
                nums[i]/=10;
                largest=max(largest,r);
                smallest=min(smallest,r);
            }
            int diff=largest-smallest;

            if(diff>maxi){
                maxi=diff;
                answer=num;
            }
            else if(diff==maxi){
                answer+=num;
            }
        }
        return answer;
    }
};