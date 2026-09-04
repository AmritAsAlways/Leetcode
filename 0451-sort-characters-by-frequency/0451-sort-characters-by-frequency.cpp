class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int>big(26,0),small(26,0),digit(10,0);
        for(int i=0;i<n;i++){
            if(s[i]-'a'>=0) small[s[i]-'a']++;
            else if(s[i]-'A'>=0)big[s[i]-'A']++;
            else digit[s[i]-'0']++;
        }
        vector<pair<char,int>>v;
        for(int i=0;i<26;i++){
            if(big[i]!=0){
                char ch='A'+i;
                v.push_back({ch,big[i]});
            }
            if(small[i]!=0){
                char ch='a'+i;
                v.push_back({ch,small[i]});
            }

            if(i<10 && digit[i]!=0){
                char ch='0'+i;
                v.push_back({ch,digit[i]}); 
            }
        }
        auto comparator=[](pair<char,int>&a,pair<char,int>&b){
            if(a.second==b.second) return a.first>b.first;
            return a.second>b.second;
        };
        sort(v.begin(),v.end(),comparator);
        n=v.size();
        string ans="";
        for(int i=0;i<n;i++){
            while(v[i].second>0){
                ans+=v[i].first;
                v[i].second--;
            }
        }
        return ans;
    }
};