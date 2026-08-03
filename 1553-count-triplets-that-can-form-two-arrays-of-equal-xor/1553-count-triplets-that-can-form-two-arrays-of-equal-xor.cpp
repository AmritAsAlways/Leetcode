class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>totalxor(n,arr[0]);
        unordered_map<int,int>um;
        for(int i=1;i<n;i++){
            totalxor[i]=totalxor[i-1]^arr[i];
            um[totalxor[i]]++;
        }
        int answer=0;
        for(int j=1;j<n;j++){
            //all the different values of i-1 for this particular j
            for(int i=0;i<j;i++){
                //for i==0 case the i-1 value is 0 so
                if(i==0){
                    if(um.count(0)) answer+=um[0];
                }
                else{
                    if(um.count(totalxor[i-1])) answer+=um[totalxor[i-1]];
                }
            }

            //removing the jth xor valuee
            um[totalxor[j]]--;
            if(um[totalxor[j]]==0) um.erase(totalxor[j]);
        }
        return answer;
    }
};