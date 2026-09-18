class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long smallest=1,largest=m*n;
        while(smallest<=largest){
            long long mid=smallest+(largest-smallest)/2;

            int present=0,position=0;

            for(int i=1;i<=m;i++){
                long long l=i*n;
                if(mid>l){
                    position+=n;
                }
                else{
                    position+=mid/i;
                    if(mid%i==0) present++;
                }
            }

            if(present==0){
                position++;

                if(k<position){
                    largest=mid-1;
                }
                else{
                    smallest=mid+1;
                }
            }
            else{
                int smallpos=position-present+1,largepos=position;
                if(k>=smallpos && k<=largepos) return (int)mid;
                if(k<smallpos) largest=mid-1;
                if(k>largepos) smallest=mid+1;
            }
        }
        return -1;
    }
};