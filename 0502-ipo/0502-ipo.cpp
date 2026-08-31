class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++) minheap.push({capital[i],profits[i]});
        while(k>0){
            while(!minheap.empty()){
                pair<int,int>p=minheap.top();
                if(p.first>w) break;
                minheap.pop();
                int profit=p.second;
                maxheap.push(profit);
            }
            cout<<endl;
            if(!maxheap.empty()){
                int profit=maxheap.top();
                w+=profit;
                maxheap.pop();
            }
            k--;
        }
        return w;
    }
};