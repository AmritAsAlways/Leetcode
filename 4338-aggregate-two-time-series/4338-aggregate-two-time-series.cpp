class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n=series1.size(),m=series2.size(),i=0,j=0;
        vector<vector<int>>v;
        while(i<n && j<m){
            if(series1[i][0]==series2[j][0]){
                v.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                i++;
                j++;
            }
            else if(series1[i][0]<series2[j][0]){
                int value=series1[i][1]+series2[j][1];
                v.push_back({series1[i][0],value});
                i++;
            }
            else if(series1[i][0]>series2[j][0]){
                int value=series2[j][1]+series1[i][1];
                v.push_back({series2[j][0],value});
                j++;
            }
        }
        while(i<n){
            v.push_back({series1[i][0],series1[i][1]});
            i++;
        }
        while(j<m){
            v.push_back({series2[j][0],series2[j][1]});
            j++;
        }
        return v;
    }
};