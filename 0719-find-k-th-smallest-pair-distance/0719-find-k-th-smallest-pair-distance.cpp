class Solution {
public:
int solve(vector<int>&nums,int d,int&k){
    int n=nums.size(),answer=0;
    for(int i=0;i<n;i++){
        auto it=upper_bound(nums.begin()+i,nums.end(),nums[i]+d);
        int index=it-nums.begin();
        index--;
        answer+=(index-i);
    }
    return answer;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int smallestdiff=INT_MAX,largestdiff=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++){
            smallestdiff=min(smallestdiff,nums[i+1]-nums[i]);
        }
        int solution=-1;
        while(smallestdiff<=largestdiff){
            int mid=smallestdiff+(largestdiff-smallestdiff)/2;

            int answer=solve(nums,mid,k);

            if(answer>=k){
                solution=mid;
                largestdiff=mid-1;
            }
            else{
                smallestdiff=mid+1;
            }
        }
        return solution;
    }
};