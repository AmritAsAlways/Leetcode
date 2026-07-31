class Solution {
public:
struct comparator{
    bool operator()(pair<double,vector<int>>&a,pair<double,vector<int>>&b){
        return a.first>b.first;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,comparator>maxheap;
        for(int i=0;i<n;i++){
            double distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            distance=pow(distance,0.5);
            maxheap.push({distance,points[i]});
        }
        vector<vector<int>>v;
        int size=0;
        while(!maxheap.empty()){
            v.push_back(maxheap.top().second);
            maxheap.pop();
            size++;
            if(size==k) break;
        }
        return v;
    }
};