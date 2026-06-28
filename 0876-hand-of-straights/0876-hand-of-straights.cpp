class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        sort(hand.begin(),hand.end());
        vector<pair<int,int>>v;
        int i=0;
        while(i<n){
            int j=i,times=0;
            while(j<n){
                if(hand[j]>hand[i]) break;
                times++;
                j++;
            }
            v.push_back({hand[i],times});
            i=j;
        }
        n=v.size();
        i=0;
        while(i<n){
            if(v[i].second<0) return false;
            if(v[i].second==0){
                i++;
                continue;
            }

            if(i+groupSize>n) return false;
            int j=i+1;
            while(j<i+groupSize){
                if(v[j].first-v[j-1].first!=1) return false;
                v[j].second-=v[i].second;
                j++;
            }
            i++;
        }
        return true;
    }
};