class Solution {
public:
pair<int,int> solve(string&s,int i,int&n){
    int sum=0;
    bool add=true;
    while(i<n){
        if(s[i]==' ' || s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') add=false;
            else if(s[i]=='+') add=true;
            i++;
            continue;
        }

        if(s[i]=='('){
            pair<int,int>p=solve(s,i+1,n);
            i=p.second;
            if(add) sum+=p.first;
            else sum-=p.first;
            continue;
        }
        else if(s[i]==')') break;

        long long digit=s[i]-'0',j=i+1;
        while(j<n){
            if(s[j]<'0' || s[j]>'9') break;
            digit*=10;
            digit+=s[j]-'0';
            j++;
        }

        if(add) sum+=digit;
        else sum-=digit;
        i=j;
    }

    return {sum,i+1};
}
    int calculate(string s) {
        s.push_back(')');
        int n=s.size();
        pair<int,int> answer=solve(s,0,n);
        return answer.first;
    }
};