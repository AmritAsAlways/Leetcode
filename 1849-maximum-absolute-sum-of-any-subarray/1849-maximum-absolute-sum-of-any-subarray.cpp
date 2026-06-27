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
            cout<<v[j]<<" ";
            j++;
        }
        cout<<endl;
        set<int>s;
        for(int i=n-1;i>=0;i--){
            s.insert(v[i]);

            int small=*s.begin(),large=*s.rbegin();
            int prev=0;
            if(i!=0) prev=v[i-1];

            cout<<small<<" "<<large<<" "<<prev<<endl;

            answer=max(answer,max(abs(small-prev),abs(large-prev)));
        }
        return answer;
    }
};