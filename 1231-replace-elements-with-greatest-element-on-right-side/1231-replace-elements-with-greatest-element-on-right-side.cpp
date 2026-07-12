class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(),greatest=-1;
        for(int i=n-1;i>=0;i--){
            int x=arr[i];
            arr[i]=greatest;
            greatest=max(greatest,x);
        }
        return arr;
    }
};