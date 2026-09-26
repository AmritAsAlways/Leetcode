class RecentCounter {
public:
priority_queue<int,vector<int>,greater<int>>minheap;
int size;
    RecentCounter() {
        size=0;
    }
    
    int ping(int t) {
        while(!minheap.empty()){
            if(minheap.top()>=t-3000) break;
            minheap.pop();
            size--;
        }
        minheap.push(t);
        size++;
        return size;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */