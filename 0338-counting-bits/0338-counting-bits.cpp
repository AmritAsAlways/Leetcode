class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        if(n==0) return v;
        v.push_back(1);
        if(n==1) return v;
        v.push_back(1);
        if(n==2) return v;
        int preveven=2;
        for(int i=3;i<=n;i++){
            int diff=i-preveven;
            if(diff!=preveven){
                v.push_back(v[diff]+v[preveven]);
            }
            else{
                v.push_back(1);
                preveven=i;
            }
        }
        return v;
    }
};