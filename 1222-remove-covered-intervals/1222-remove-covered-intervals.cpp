class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int answer=0,i=0;
        while(i<n){
            int start=intervals[i][0],end=intervals[i][1],j=i+1;
            while(j<n){
                if(intervals[j][1]>end) break;
                answer++;
                j++;
            }
            i=j;
        }
        return n-answer;
    }
};