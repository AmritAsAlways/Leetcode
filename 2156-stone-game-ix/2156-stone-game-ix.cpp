class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size(),zero=0,one=0,two=0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0) zero++;
            else if(stones[i]%3==1) one++;
            else if(stones[i]%3==2) two++;
        }
        if(zero%2==0){ 
            return  ((one>=1 && two>=1) && (two>=one || one>=two));
        }
        return abs(one-two)>2;
    }
};