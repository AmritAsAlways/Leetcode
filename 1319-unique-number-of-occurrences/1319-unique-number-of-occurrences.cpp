class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>um;
        unordered_set<int>us;
        for(int i=0;i<n;i++) um[arr[i]]++;
        for(auto&it:um){
            if(us.find(it.second)==us.end()){
                us.insert(it.second);
            }
            else return false;
        }
        return true;
    }
};