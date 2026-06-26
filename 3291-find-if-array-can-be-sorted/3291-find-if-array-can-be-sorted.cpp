class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>setbit(n,0);
        for(int i=0;i<n;i++){
            setbit[i]=__builtin_popcount(nums[i]);
        }
        int i=0;
        while(i<n){
            int j=i;
            while(j<n){
                if(setbit[j]!=setbit[i]) break;
                j++;
            }
            sort(nums.begin()+i,nums.begin()+j);
            i=j;
        }
        i=0;
        while(i<n-1){
            if(nums[i+1]<nums[i]) return false;
            i++;
        }
        return true;
    }
};