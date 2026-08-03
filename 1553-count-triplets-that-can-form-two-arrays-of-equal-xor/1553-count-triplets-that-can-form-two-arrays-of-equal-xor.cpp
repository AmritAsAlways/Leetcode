class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>totalxor(n,arr[0]);
        for(int i=1;i<n;i++) totalxor[i]=totalxor[i-1]^arr[i];
        int answer=0;
        for(int i=1;i<n;i++){
            unordered_map<int,int>um;
            //all the possible xor values from index 0 to j-1
            for(int j=0;j<i;j++){
                if(j==0) um[totalxor[i-1]]++;
                else um[totalxor[i-1]^totalxor[j-1]]++;
            }
            //all the possible xor values from index j to k
            for(int k=i;k<n;k++){
                int xorvalue=totalxor[k]^totalxor[i-1];
                if(um.count(xorvalue)) answer+=um[xorvalue];
            }
            cout<<answer<<endl;
        }
        return answer;
    }
};