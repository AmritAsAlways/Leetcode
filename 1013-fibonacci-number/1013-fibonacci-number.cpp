class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int secondprev=0,prev=1;
        while(n-2>0){
            int curr=prev+secondprev;
            secondprev=prev;
            prev=curr;
            n--;
        }
        return secondprev+prev;
    }
};