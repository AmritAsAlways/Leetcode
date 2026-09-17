class Solution {
public:
void solve(int open,int closed,vector<string>&v,string s){
    if(open>closed || open<0 || closed<0) return;
    if(open==0 && closed==0){
        v.push_back(s);
        return;
    }

    //use open
    s+='(';
    solve(open-1,closed,v,s);
    s.pop_back();

    //use closed
    s+=')';
    solve(open,closed-1,v,s);
    s.pop_back();
}
    vector<string> generateParenthesis(int n) {
        int open=n,closed=n;
        string s="";
        vector<string>v;
        solve(open,closed,v,s);
        return v;
    }
};