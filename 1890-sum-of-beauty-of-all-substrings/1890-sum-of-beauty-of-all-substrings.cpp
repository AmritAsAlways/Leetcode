class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),answer=0;
        for(int i=0;i<n;i++){
            vector<int>v(26,0);
            for(int j=i;j<n;j++){
                v[s[j]-'a']++;
                int mostfreq=INT_MIN,leastfreq=INT_MAX;
                for(int k=0;k<26;k++){
                    if(v[k]!=0) mostfreq=max(mostfreq,v[k]);
                    if(v[k]!=0) leastfreq=min(leastfreq,v[k]);
                }
                answer+=(mostfreq-leastfreq);
            }
        }
        return answer;
    }
};