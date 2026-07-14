class Solution {
public:
void solve(string&s,bool tight,int idx,int prev,bool leadingzero,unordered_set<string>&us,string temp,int&n){
    //base condition
    if(idx==n){
        if(us.count(temp)) us.erase(temp);
        else us.insert(temp);
        return;
    }

    int lowerbound=0,upperbound=(tight) ? s[idx]-'0' : 9;
    for(int digit=lowerbound;digit<=upperbound;digit++){
        //invalid cases
        if(prev!=0 && digit!=prev+1) continue;
        string t=temp+to_string(digit);
        solve(s,(tight && digit==upperbound),idx+1,digit,(leadingzero && digit==0),us,t,n);
    }
}
    vector<int> sequentialDigits(int low, int high) {
        low--;
        string s=to_string(high),t=to_string(low);
        int n=s.size(),m=t.size();
        while(m<n){
            t="0"+t;
            m++;
        }
        unordered_set<string>us;
        solve(s,true,0,0,true,us,"",n);
        solve(t,true,0,0,true,us,"",n);
        vector<int>ans;
        for(auto it=us.begin();it!=us.end();++it){
            ans.push_back(stoi(*it));
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};