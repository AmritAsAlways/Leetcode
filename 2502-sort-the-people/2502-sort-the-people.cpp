class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=heights.size();
        vector<pair<int,int>>v(n,{0,0});
        for(int i=0;i<n;i++){
            v[i].first=heights[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        vector<string>answer(n,"");
        for(int i=0;i<n;i++){
            answer[i]=names[v[i].second];
        }
        return answer;
    }
};