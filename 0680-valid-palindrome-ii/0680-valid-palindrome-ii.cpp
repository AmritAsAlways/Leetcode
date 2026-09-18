class Solution {
public:
bool palindrome(string&s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int n=s.size(),i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]){
                if(palindrome(s,i+1,j)==true || palindrome(s,i,j-1)==true) return true;
                else return false;
            }
            i++;
            j--;
        }
        return true;
    }
};