class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        vector<int>lower(26,0),upper(26,0);
        for(int i=0;i<n;i++){
            if(s[i]>='a') lower[s[i]-'a']++;
            else upper[s[i]-'A']++;
        }
        int answer=0,odd=0,totalodd=0,maxiodd=0;
        for(int i=0;i<26;i++){
            if(lower[i]!=0){
                if(lower[i]%2==0) answer+=lower[i];
                else{
                    odd++;
                    totalodd+=lower[i];
                    maxiodd=max(maxiodd,lower[i]);
                }
            }

            if(upper[i]!=0){
                if(upper[i]%2==0) answer+=upper[i];
                else{
                    odd++;
                    totalodd+=upper[i];
                    maxiodd=max(maxiodd,upper[i]);
                }
            }
        }

        totalodd-=odd;
        answer+=totalodd;

        if(maxiodd!=0) answer++;
        return answer;

    }
};