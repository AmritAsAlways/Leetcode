class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++) v[text[i]-'a']++;
        int value=INT_MAX;
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(ch=='l' || ch=='o') v[i]/=2;
            if(ch=='a' || ch=='b' || ch=='l' || ch=='o' || ch=='n') value=min(value,v[i]);
        }
        return value;
    }
};