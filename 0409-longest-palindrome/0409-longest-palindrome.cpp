class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        vector<int>lower(26,0),upper(26,0);
        for(int i=0;i<n;i++){
            if(s[i]>='a') lower[s[i]-'a']++;
            else upper[s[i]-'A']++;
        }
        int answer=0,odd=0;
        for(int i=0;i<26;i++){
            answer+=upper[i]+lower[i];
            if(upper[i]%2!=0){
                answer--;
                odd=max(odd,upper[i]);
            }
            if(lower[i]%2!=0){
                answer--;
                odd=max(odd,lower[i]);
            }
        }
        if(odd!=0) answer++;
        return answer;
    }
};