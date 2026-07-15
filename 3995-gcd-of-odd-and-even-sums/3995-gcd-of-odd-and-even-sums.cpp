class Solution {
public:
int solve(int a,int b){
    if(a==0) return b; 
    return solve(b%a,a);
}
    int gcdOfOddEvenSums(int n) {
        int sumeven=n*(n+1);
        int sumodd=sumeven-n;
        return solve(sumeven,sumodd);
    }
};