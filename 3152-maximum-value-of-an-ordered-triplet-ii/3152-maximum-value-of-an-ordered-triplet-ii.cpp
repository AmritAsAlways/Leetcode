class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>ahead(n,0),prev(n,0);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            ahead[i]=maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        maxi=INT_MIN;
        for(int i=0;i<n;i++){
            prev[i]=maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        long long answer=0;
        for(int i=1;i<n-1;i++){
            long long diff=prev[i]-nums[i];
            diff=diff*ahead[i];
            answer=max(answer,diff);
        }
        return answer;
    }
};