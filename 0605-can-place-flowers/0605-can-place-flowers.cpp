class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size(),i=0,j=m-1,flowers=0,zero=0;
        while(i<m){
            if(flowerbed[i]==1) break;
            zero++;
            i++;
        }
        if(i==m){
            if(zero%2!=0) zero++;
            return (zero/2>=n) ? true : false;
        }
        flowers+=zero/2;
        zero=0;
        cout<<flowers<<endl;
        while(j>=0 && j>=i){
            if(flowerbed[j]==1) break;
            j--;
            zero++;
        }
        flowers+=zero/2;
        cout<<flowers<<endl;
        cout<<i<<" "<<j<<endl;
        while(i<=j){
            int k=i+1;
            zero=0;
            while(k<=j){
                if(flowerbed[k]==1) break;
                k++;
                zero++;
            }
            zero-=2;
            if(zero>=0){
                if(zero%2!=0) zero++;
                flowers+=zero/2;
            }
            i=k;
        }
        cout<<flowers<<endl;
        return (flowers>=n) ? true : false;
    }
};