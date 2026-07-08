class Solution {
public:
using ll=long long;
    long long sumAndMultiply(int n) {
        int sum=0,i=0;
        string s="";
        while(n>0){
            int r=n%10;
            n/=10;
            sum+=r;
            if(r!=0){
                char ch='0'+r;
                s+=ch;
            }
        }
        ll ans=0;
        n=s.size(),i=n-1;
        while(i>=0){
            ans=ans*10+s[i]-'0';
            i--;
        }
        return ans*1LL*sum;
    }
};