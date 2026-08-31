class MedianFinder {
public:
int total=0;
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        total++;

        if(total%2!=0){
            if(maxheap.empty() || maxheap.top()>=num){
                maxheap.push(num);
                return;
            }
            minheap.push(num);
            int mini=minheap.top();
            minheap.pop();

            maxheap.push(mini);
            return;
        }

        maxheap.push(num);
        int maxi=maxheap.top();
        maxheap.pop();

        minheap.push(maxi);
    }
    
    double findMedian() {
        if(total%2!=0) return maxheap.top();
        double first=maxheap.top();
        first+=minheap.top();
        return first/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */