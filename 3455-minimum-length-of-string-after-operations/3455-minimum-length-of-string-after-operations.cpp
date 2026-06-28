class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        int answer=0;
        for(int i=0;i<26;i++){
            if(v[i]%2==0 && v[i]!=0) answer+=2;
            else if(v[i]%2!=0) answer+=1;
        }
        return answer;
    }
};