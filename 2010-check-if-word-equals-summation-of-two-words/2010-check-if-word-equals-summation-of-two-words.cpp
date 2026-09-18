class Solution {
public:
long long solve(string&s){
    int n=s.size();
    long long num=0;
    for(int i=0;i<n;i++){
        int x=s[i]-'a';
        num*=10;
        num+=x;
    }
    return num;
}
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        long long first=solve(firstWord),second=solve(secondWord),target=solve(targetWord);
        return (first+second==target) ? true : false;
    }
};