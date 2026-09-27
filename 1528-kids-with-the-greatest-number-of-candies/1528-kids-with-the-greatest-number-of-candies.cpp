class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size(),maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(candies[i],maxi);
        vector<bool>v(n,false);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi) v[i]=true;
        }
        return v;
    }
};