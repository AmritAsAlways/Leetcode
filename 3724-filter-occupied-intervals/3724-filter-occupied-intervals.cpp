class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        //merged intervals
        vector<vector<int>>v;
        int i=0;
        while(i<n){
            int start=occupiedIntervals[i][0],end=occupiedIntervals[i][1];
            int j=i+1;
            while(j<n){
                if(occupiedIntervals[j][0]>end+1) break;
                end=max(occupiedIntervals[j][1],end);
                j++;
            }
            cout<<start<<" "<<end<<endl;
            v.push_back({start,end});
            i=j;
        }
        vector<vector<int>>ans;
        n=v.size();
        i=0;
        while(i<n){
            if(v[i][1]<freeStart || v[i][0]>freeEnd){
                ans.push_back({v[i][0],v[i][1]});
                i++;
                continue;
            }


            if(v[i][0]<freeStart && v[i][1]>=freeStart){
                ans.push_back({v[i][0],freeStart-1});
                if(v[i][1]>freeEnd) ans.push_back({freeEnd+1,v[i][1]});
            }
            else if(v[i][0]>=freeStart && v[i][0]<freeEnd){
                if(v[i][1]>freeEnd) ans.push_back({freeEnd+1,v[i][1]});
            }
            else if(v[i][0]==freeEnd){
                if(v[i][1]>freeEnd) ans.push_back({freeEnd+1,v[i][1]});
            }
            i++;
        }
        return ans;
    }
};