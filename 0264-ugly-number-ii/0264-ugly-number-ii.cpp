class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        priority_queue<long long,vector<long long>,greater<long long>>minheap;
        n--;
        unordered_set<long long>um;
        um.insert(2);
        um.insert(3);
        um.insert(5);
        minheap.push(2);
        minheap.push(3);
        minheap.push(5);
        while(n>1){
            long long num=minheap.top();
            minheap.pop();

            long long num1=num*2,num2=num*3,num3=num*5;
            if(um.find(num1)==um.end()){
                um.insert(num1);
                minheap.push(num1);
            }
            if(um.find(num2)==um.end()){
                um.insert(num2);
                minheap.push(num2);
            }
            if(um.find(num3)==um.end()){
                um.insert(num3);
                minheap.push(num3);
            }
            n--;
        }
        return minheap.top();
    }
};