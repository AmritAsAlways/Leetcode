class Solution {
public:
    int maxDifference(string s) {
        int n=s.size(),i=0;
        vector<int>v(26,0);
        while(i<n){
            v[s[i]-'a']++;
            i++;
        }
        int odd=0,even=INT_MAX;
        i=0;
        while(i<26){
            if(v[i]%2==0 && v[i]!=0) even=min(even,v[i]);
            else if(v[i]%2!=0 && v[i]!=0) odd=max(odd,v[i]);  
            i++;
        }
        return odd-even;
    }
};