class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int start=0,end=m-1,answer=-1;
            while(start<=end){
                int mid=start+(end-start)/2;

                long long strength=1LL*spells[i]*potions[mid];
                if(strength>=success){
                    answer=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            if(answer==-1){
                ans.push_back(0);
            }
            else{
                ans.push_back(m-answer);
            }
        }
        return ans;
    }
};