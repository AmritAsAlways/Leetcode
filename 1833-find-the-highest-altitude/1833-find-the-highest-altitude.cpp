class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size(),maxi=0,height=0,i=0;
        while(i<n){
            height+=gain[i];
            maxi=max(maxi,height);
            i++;
        }
        return maxi;
    }
};