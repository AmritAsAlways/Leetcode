class Solution {
public:
struct comparator{
    bool operator()(const pair<int,string>&a,const pair<int,string>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>um;
        for(int i=0;i<n;i++) um[words[i]]++;
        //now i will put all the strings and the number of times it came in a priority_queue and first sort it according to the number of times and if number of times is same then lexicographically 
        //so i have to use maxheap with custome constructor here
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>maxheap;
        for(auto&it:um){
            maxheap.push({it.second,it.first});
        }
        vector<string>v;
        while(k>0){
            pair<int,string>p=maxheap.top();
            maxheap.pop();

            v.push_back(p.second);
            k--;
        }
        return v;

    }
};