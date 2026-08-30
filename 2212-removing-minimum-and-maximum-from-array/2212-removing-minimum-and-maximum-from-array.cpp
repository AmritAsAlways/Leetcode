class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,maxindex=-1,mini=INT_MAX,minindex=-1;
        bool leftmaxi=false,leftmini=false,rightmaxi=false,rightmini=false;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxindex=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minindex=i;
            }
        }

        //for max number
        int maxdiff=min(maxindex+1,n-maxindex),mindiff=min(minindex+1,n-minindex);
        if(maxindex+1<=(n-maxindex)){
            leftmaxi=true;
        }
        else rightmaxi=true;

        //for min index
        if(minindex+1<=(n-minindex)){
            leftmini=true;
        }
        else rightmini=true;

        int count=0;
        if(mindiff<=maxdiff){
            count+=mindiff;
            int start=0,end=n-1;
            if(leftmini){
                start=minindex+1;
            }
            else{
                end=minindex-1;
            }

            count+=min(maxindex-start+1,end-maxindex+1);

        }
        else{
            count+=maxdiff;
            int start=0,end=n-1;
            if(leftmaxi){
                start=maxindex+1;
            }
            else{
                end=maxindex-1;
            }

            count+=min(minindex-start+1,end-minindex+1);

        }

        return count;
    }
};