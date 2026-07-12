class Solution {
public:
bool solve(string&s,string&t){
    int n=s.size(),m=t.size();
    int j=0;
    while(j<=t.size()-n){
        if(t[j]!=s[0]){
            j++;
            continue;
        }
        int i=0,z=j;
        bool check=true;
        while(i<n){
            if(s[i]!=t[j]){
                check=false;
                break;
            }
            i++;
            j++;
        }
        if(check) return true;
        j=z+1;
    }   
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const string&a,const string&b){
            return a.size()<b.size();
        });
        vector<string>v;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(solve(words[i],words[j])){
                    v.push_back(words[i]);
                    break;
                }
            }
        }
        return v;
    }
};