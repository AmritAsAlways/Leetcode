class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n=x.size(),i=0;
        vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=0;i<n;i++) v.push_back({x[i],i});
        sort(v.begin(),v.end());
        while(i<n){
            int j=i,maximum=INT_MIN;
            while(j<n){
                if(v[j].first!=v[i].first) break;
                maximum=max(maximum,y[v[j].second]);
                j++;
            }
            i=j;
            ans.push_back(maximum);
        }
        int m=ans.size();
        if(m<3) return -1;
        sort(ans.begin(),ans.end());
        return ans[m-1]+ans[m-2]+ans[m-3];
    }
};