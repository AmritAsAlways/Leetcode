class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(),i=0,answer=0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        while(i<n-1){
            if(intervals[i+1][0]>=intervals[i][1]){
                i++;
                continue;
            }

            int end=min(intervals[i+1][1],intervals[i][1]);
            int j=i+2;
            while(j<n){
                if(intervals[j][0]>=end) break;
                end=min(end,intervals[j][1]);
                j++;
            }
            answer+=(j-i-1);
            i=j;
        }
        return answer;
    }
};