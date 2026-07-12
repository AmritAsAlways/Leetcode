class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size(),i=0,answer=0;
        sort(nums.begin(),nums.end());
        while(i<n){
            int j=i+1;
            while(j<n){
                if(nums[j]!=nums[i]) break;
                j++;
            }
            int len=j-i;
            int total=len*(len-1);
            total/=2;
            answer+=total;
            i=j;
        }
        return answer;
    }
};