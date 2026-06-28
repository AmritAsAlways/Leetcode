class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int swaps=0,ones=0,answer=INT_MAX;
        for(int i=0;i<n;i++) if(nums[i]==1) ones++;
        for(int i=0;i<ones;i++){
            if(nums[i]==0) swaps++;
        }
        if(ones==0) return 0;
        int i=0,j=ones-1;
        answer=min(answer,swaps);
        cout<<swaps<<" "<<ones<<endl;
        while(i<n){
            if(nums[i]==0){
                swaps--;
            }
            j++;
            j%=n;
            if(nums[j]==0){
                swaps++;
            }
            i++;
            answer=min(answer,swaps);
        }
        return answer;
    }
};