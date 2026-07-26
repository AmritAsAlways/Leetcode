class Solution {
public:
    int largestInteger(int n, int s) {
        //condition of -1 
        if(s>9*n) return -1;
        int digit=9,ans=0;
        while(n>0){
            if(digit<=s){
                ans=ans*10+digit;
                n--;
                s-=digit;
            }
            else{
                digit--;
            }
        }
        return ans;
    }
};