class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size(),m=word.size();
        unordered_map<string,int>um;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=i;j<m;j++){
                s+=word[j];
                um[s]++;
            }
        }
        int answer=0;
        for(int i=0;i<n;i++){
            if(um.count(patterns[i])) answer++;
        }
        return answer;
    }
};