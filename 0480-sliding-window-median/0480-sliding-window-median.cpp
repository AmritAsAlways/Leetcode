class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double>ans;
        if(k==1){
            for(int i=0;i<n;i++) ans.push_back(nums[i]);
            return ans;
        }
        auto comp=[](const pair<double,double>&a,const pair<double,double>&b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        };
        set<pair<double,double>,decltype(comp)>maxheap(comp);
        auto comp1=[](const pair<double,double>&a,const pair<double,double>&b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        };
        set<pair<double,double>,decltype(comp1)>minheap(comp1);
        for(int i=0;i<k;i++) maxheap.insert({nums[i],i});
        for(int i=0;i<k/2;i++){
            pair<int,int>p=*maxheap.begin();
            maxheap.erase(p);

            minheap.insert(p);
        }

        double total=0;
        total+=maxheap.begin()->first;
        if(k%2==0){
            total+=minheap.begin()->first;
            total/=2;
        }
        ans.push_back(total);

        for(int i=k;i<n;i++){
            pair<int,int>f={nums[i-k],i-k};
            bool maxset=true;
            if(maxheap.count(f)) maxheap.erase(f);
            else{
                minheap.erase(f);
                maxset=false;
            }

            pair<int,int>p={nums[i],i};
            if(maxset) maxheap.insert(p);
            else minheap.insert(p);

            pair<double,double>a=*maxheap.begin();
            pair<double,double>b=*minheap.begin();

            if(a.first>b.first){
                maxheap.erase(a);
                minheap.erase(b);
                maxheap.insert(b);
                minheap.insert(a);
            }


            total=maxheap.begin()->first;
            if(k%2==0){
                total+=minheap.begin()->first;
                total/=2;
            }
            ans.push_back(total);
        }
        return  ans;
    }
};