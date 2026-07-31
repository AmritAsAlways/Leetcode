class Solution {
public:
struct comparator{
    bool operator()(pair<char,int>&a,pair<char,int>&b){
        return a.second<b.second;
    }
};
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>um;
        for(int i=0;i<n;i++) um[s[i]]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,comparator>maxheap;
        for(auto&it:um){
            maxheap.push({it.first,it.second});
        }
        string answer="";
        while(!maxheap.empty()){
            pair<char,int>ans=maxheap.top();
            while(ans.second>0){
                answer+=ans.first;
                ans.second--;
            }
            maxheap.pop();
        }
        return answer;
    }
};