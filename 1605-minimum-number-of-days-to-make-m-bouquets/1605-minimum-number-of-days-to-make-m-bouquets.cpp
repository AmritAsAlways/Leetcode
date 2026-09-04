class Solution {
public:
bool solve(vector<int>&bloomDay,int&m,int mid,int&k){
    int n=bloomDay.size(),i=0;

    vector<int>bloomedflower(n,0);
    for(int i=0;i<n;i++){
        if(mid>=bloomDay[i]) bloomedflower[i]=1;
        if(i!=0) bloomedflower[i]+=bloomedflower[i-1];
    }

    int bouquets=0,right=k-1;
    while(right<n){
        int left=right-k;
        int flowerbloomed=bloomedflower[right];
        if(left>=0) flowerbloomed-=bloomedflower[left];

        if(flowerbloomed==k){
            right+=k;
            bouquets++;
        }
        else right++;
    }    

    if(bouquets>=m){
        return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long totalflowerneeded=1LL*m*k;
        if(totalflowerneeded>1LL*n) return -1;

        int start=0,end=-1;//the minimum and maximum day after which we can make the bouquets
        for(int i=0;i<n;i++) end=max(end,bloomDay[i]);
        int days=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            bool check=solve(bloomDay,m,mid,k); //can in this days we can make bouquets

            if(check){
                days=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return days;
    }
};