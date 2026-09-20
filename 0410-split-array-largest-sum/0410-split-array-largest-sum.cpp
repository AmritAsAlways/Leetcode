class Solution {
public:
int solve(vector<int>&nums,long long target,int k){
    int n=nums.size(),i=0;
    int parts=0;
    long long sum=0;
    bool check=true;
    while(i<n){
        if(nums[i]>target){
            check=false;
            break;
        }

        sum+=nums[i];
        if(sum>target){
            parts++;
            sum=nums[i];
        }
        i++;
    }
    if(sum!=0) parts++;

    if(!check) return -1;

    return parts;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long start=0,end=0;
        for(int i=0;i<n;i++) end+=nums[i];
        long long answer=0;
        while(start<=end){
            long long mid=start+(end-start)/2;

            int parts=solve(nums,mid,k);
            if(parts==-1){
                start=mid+1;
                continue;
            }


            if(parts<=k){
                answer=mid;
                end=mid-1;
            }
            else if(parts>k){
                start=mid+1;
            }
        }
        int i=0;
        int sum=0,maxi=INT_MIN;
        while(i<n){
            sum+=nums[i];
            if(sum>answer){
                sum=nums[i];
            }
            maxi=max(sum,maxi);
            i++;
        }
        return maxi;
    }
};