class Solution {
public:
string small(vector<int>&v){
    string t="";
    for(int i=0;i<26;i++){
        if(v[i]!=0){
            t+='a'+i;
            v[i]--;
        }
    }
    return t;
}
string large(vector<int>&v){
    string t="";
    for(int i=25;i>=0;i--){
        if(v[i]!=0){
            t+='a'+i;
            v[i]--;
        }
    }
    return t;
}
    string sortString(string s) {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        string answer="";
        while(1){
            string smallest=small(v);
            if(smallest=="") break;
            answer+=smallest;
            string largest=large(v);
            if(largest=="") break;
            answer+=largest;
        }
        return answer;
    }
};