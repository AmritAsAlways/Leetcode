class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long i=1e3,ans=0;
        int comma=1;
        while(i<=n){
            if(n<i) break;
            long long next=i*1e3;
            if(n>=next){
                ans+=(next-i)*comma;
            }
            else{
                ans+=(n-i+1)*comma;
            }
            comma++;
            i=next;
        }
        return ans;
    }
};