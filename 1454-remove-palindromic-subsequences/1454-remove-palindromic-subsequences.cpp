class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size(),i=0,j=n-1;
        //if the string is already a palindrome
        bool palindrome=true;
        while(i<=j){
            if(s[i]!=s[j]){
                palindrome=false;
                break;
            }
            i++;
            j--;
        }
        if(palindrome) return 1;
        //first remove all a's then remove all b's
        return 2;
    }
};