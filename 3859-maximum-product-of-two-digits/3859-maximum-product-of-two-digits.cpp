class Solution {
public:
    int maxProduct(int n) {
        int maxi=-1,secondmax=-1;
        while(n>0){
            int r=n%10;
            if(r>=maxi){
                secondmax=maxi;
                maxi=r;
            }
            else if(r>=secondmax) secondmax=r;
            n/=10;
        }
        return maxi*secondmax;
    }
};