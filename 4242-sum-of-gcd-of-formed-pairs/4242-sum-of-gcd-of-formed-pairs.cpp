class Solution {
public:
using ll=long long;
long long gcd(long long a,long long b){
    if(a==0) return b;
    return gcd(b%a,a);
}
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        vector<ll>v(n,0);
        for(int i=0;i<n;i++){
            maxi=max(maxi,(ll)nums[i]);
            v[i]=gcd(nums[i],maxi);
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        ll answer=0;
        while(i<j){
            answer+=gcd(v[i],v[j]);
            i++;
            j--;
        }
        return answer;
    }
};