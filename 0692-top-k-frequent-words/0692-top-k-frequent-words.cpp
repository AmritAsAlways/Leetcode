class Solution {
public:
struct comparator{
    bool operator()(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>um;
        for(int i=0;i<n;i++) um[words[i]]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,comparator>minheap;
        int size=0;
        for(auto&it:um){
            if(size==k){
                if(minheap.top().second<it.second || minheap.top().second==it.second && minheap.top().first>it.first){
                    minheap.pop();
                    minheap.push({it.first,it.second});
                }
            }
            else{
                minheap.push({it.first,it.second});
                size++;
            }
        }
        vector<string>v(k,"");
        while(!minheap.empty()){
            v[size-1]=minheap.top().first;
            minheap.pop();
            size--;
        }
        return v;
    }
};