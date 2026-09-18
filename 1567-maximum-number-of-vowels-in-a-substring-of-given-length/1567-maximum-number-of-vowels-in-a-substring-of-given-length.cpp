class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size(),vowel=0;
        for(int j=0;j<k;j++){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')  vowel++;
        }
        int answer=0,j=k;
        answer=max(answer,vowel);
        while(j<n){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')  vowel++;
            if(s[j-k]=='a' || s[j-k]=='e' || s[j-k]=='i' || s[j-k]=='o' || s[j-k]=='u')  vowel--;
            answer=max(answer,vowel);
            j++;
        }
        return answer;
    }
};