class SummaryRanges {
public:
set<int>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>v;
        auto i=s.begin();
        while(i!=s.end()){
            int start=*i,end=start;
            auto j=next(i);
            while(j!=s.end()){
                int value=*j;
                if(value>end+1) break;
                end=value;
                j=next(j);
            }
            v.push_back({start,end});
            i=j;
        }
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */