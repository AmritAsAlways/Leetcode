class Solution {
public:
bool solve(string s,string t){
    int n=s.size(),m=t.size();

    if(n>m) return false;

    cout<<m-n<<endl;

    for(int i=0;i<=m-n;i++){
        bool check=true;
        int j=i,a=0;
        while(a<n){
            if(s[a]!=t[j]){
                check=false;
                break;
            }
            a++;
            j++;
        }

        if(check) return true;
    }
    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int answer=0;
        for(int i=0;i<n;i++){
            if(solve(patterns[i],word)) answer++;
        }
        return answer;
    }
};