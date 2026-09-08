class Solution {
public:
    int countCommas(int n) {
        if(n<=999) return 0;
        if(n<10000){
            return n-1000+1;
        }
        return 9999-1000+1+(n-10000+1);
    }
};