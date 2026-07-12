class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size(),i=0;
        while(i<m){
            if(flowerbed[i]==1 && i+1<m && flowerbed[i+1]==1) return false;
            if(flowerbed[i]==1){
                i++;
                continue;
            }

            bool left=false,right=false;
            if(i-1>=0 && flowerbed[i-1]==0) left=true;
            if(i==0) left=true;
            if(i+1<m && flowerbed[i+1]==0) right=true;
            if(i+1==m) right=true;
            if(left && right){
                flowerbed[i]=1;
                n--;
            }
            i++;
        }
        return n<=0;
    }
};