class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int answer=0,j=0;
        vector<int>v(n,0);
        int sum=0;
        while(j<n){
            v[j]=nums[j]+sum;
            sum=v[j];
            j++;
        }
        int small=v[n-1],large=v[n-1];
        for(int i=n-1;i>=0;i--){
            if(v[i]<small) small=v[i];
            if(v[i]>large) large=v[i];
            int prev=0;
            if(i!=0) prev=v[i-1];

            answer=max(answer,max(abs(small-prev),abs(large-prev)));
        }
        return answer;
    }
};