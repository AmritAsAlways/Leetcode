class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>>minheap;
        unordered_set<long long>us;
        minheap.push(1);
        us.insert(1);
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