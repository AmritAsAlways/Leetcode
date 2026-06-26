class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int answer=0;
        for(int j=1;j<n;j++){
            unordered_map<int,int>um;
            int a=0;
            for(int i=j-1;i>=0;i--){
                a^=arr[i];
                um[a]++;
            }
            int b=0;
            for(int k=j;k<n;k++){
                b^=arr[k];
                if(um.count(b)) answer+=um[b];
            }
        }
        return answer;
    }
};