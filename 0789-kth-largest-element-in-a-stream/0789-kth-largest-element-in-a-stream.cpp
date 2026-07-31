class KthLargest {
public:
struct comparator{
    bool operator()(int&a,int&b){
        return a>b;
    };
};
priority_queue<int,vector<int>,comparator>minheap;
int size=0,target=0;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(size==k){
                if(minheap.top()<nums[i]){
                    minheap.pop();
                    minheap.push(nums[i]);
                }
            }
            else{
                minheap.push(nums[i]);
                size++;
            }
        }
        target=k;
    }
    
    int add(int val) {
        if(size==target && minheap.top()<val){
            minheap.pop();
            minheap.push(val);
        }
        else if(size<target){
            minheap.push(val);
            size++;
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */