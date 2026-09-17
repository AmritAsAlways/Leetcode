class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long start=1,end=0,answer=INT_MAX;
        for(int i=0;i<n;i++) end+=piles[i];
        while(start<=end){
            long long mid=start+(end-start)/2;

            long long days=0;
            for(int i=0;i<n;i++){
                days+=1LL*piles[i]/mid;
                if(1LL*piles[i]%mid!=0) days++;
            }

            if(days<=1LL*h){
                answer=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return (int)answer;
    }
};