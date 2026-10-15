class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        n--;
        unordered_set<long long>us;
        priority_queue<long long,vector<long long>,greater<long long>>minheap;
        minheap.push(2);
        minheap.push(3);
        minheap.push(5);
        us.insert(2);
        us.insert(3);
        us.insert(5);
        while(n>1){
            long long mini=minheap.top();
            minheap.pop();

            if(us.find(mini*2)==us.end()){
                us.insert(mini*2);
                minheap.push(mini*2);
            }
            if(us.find(mini*3)==us.end()){
                us.insert(mini*3);
                minheap.push(mini*3);
            }
            if(us.find(mini*5)==us.end()){
                us.insert(mini*5);
                minheap.push(mini*5);
            }
            n--;
        }
        return minheap.top();
    }
};