class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),answer=0,i=0;
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        while(i<n){
            int end=points[i][1],j=i+1;
            while(j<n){
                if(points[j][0]>end) break;
                end=min(points[j][1],end);
                j++;
            }
            answer++;
            i=j;
        }
        return answer;
    }
};