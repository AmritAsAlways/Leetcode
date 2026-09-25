class Solution {
public:
struct comparator{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.first>b.first;
        return a.first>b.first;
    }
};
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size(),i=0,j=n-1;
        long long answer=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>leftminheap,rightminheap;
        while(i<candidates){
            leftminheap.push({costs[i],i});
            i++;
        }
        while(candidates>0 && j>=i){
            rightminheap.push({costs[j],j});
            candidates--;
            j--;
        }
        while(i<=j && k>0){
            int x=leftminheap.top().first,y=rightminheap.top().first;
            if(x<=y){
                answer+=x;
                leftminheap.pop();
                leftminheap.push({costs[i],i});
                i++;
            }
            else{
                answer+=y;
                rightminheap.pop();
                rightminheap.push({costs[j],j});
                j--;
            }
            k--;
        }
        if(k==0) return answer;

        while(!rightminheap.empty()){
            pair<int,int>p=rightminheap.top();
            rightminheap.pop();

            leftminheap.push(p);
        }
        while(k>0){
            answer+=leftminheap.top().first;
            leftminheap.pop();
            k--;
        }
        return answer;
    }
};