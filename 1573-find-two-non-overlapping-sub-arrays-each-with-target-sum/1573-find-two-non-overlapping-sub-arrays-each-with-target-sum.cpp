class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>distance(n,0);
        for(int i=1;i<n;i++) arr[i]+=arr[i-1];
        int prev=0;
        for(int i=0;i<n;i++){
            int total=prev+target;

            int start=i,end=n-1,answer=-1;
            while(start<=end){
                int mid=start+(end-start)/2;

                if(arr[mid]==total){
                    answer=mid;
                    end=mid-1;
                }
                else if(arr[mid]>total){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            if(answer!=-1){
                distance[i]=answer-i+1;
            }
            else{
                distance[i]=INT_MAX;
            }

            prev=arr[i];
        }
        vector<int>best(n);
        int smallestdistance=INT_MAX;
        for(int i=n-1;i>=0;i--){
            smallestdistance=min(distance[i],smallestdistance);
            best[i]=smallestdistance;
        }

        int solution=INT_MAX;
        for(int i=0;i<n;i++){
            if(distance[i]==INT_MAX || i+distance[i]==n) continue;

            int idx=i+distance[i];
            if(best[idx]==INT_MAX) continue;

            solution=min(solution,distance[i]+best[idx]);
        }
        if(solution==INT_MAX) return -1;
        return solution;
    }
};