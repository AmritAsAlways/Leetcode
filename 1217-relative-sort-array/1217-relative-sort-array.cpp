class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr2.size(),m=arr1.size(),j=m-1;
        unordered_set<int>us;
        unordered_map<int,int>um;
        for(int i=0;i<n;i++) us.insert(arr2[i]);
        for(int i=m-1;i>=0;i--){
            if(us.count(arr1[i])) um[arr1[i]]++;
            else{
                arr1[j]=arr1[i];
                j--;
            }
        }
        sort(arr1.begin()+j+1,arr1.end());
        int i=0;
        j=0;
        while(i<n){
            int value=um[arr2[i]];
            while(value>0){
                arr1[j]=arr2[i];
                j++;
                value--;
            }
            i++;
        }
        return arr1;
    }
};