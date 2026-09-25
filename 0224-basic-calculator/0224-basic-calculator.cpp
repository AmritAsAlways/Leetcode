class Solution {
public:
int solve(string&s,int&i,int&n){
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
            i++;
            int x=solve(s,i,n);
            if(add) sum+=x;
            else sum-=x;
            continue;
        }
        else if(s[i]==')'){
            i++;
            break;
        }

        long long digit=s[i]-'0';
        int j=i+1;
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

    return sum;
}
    int calculate(string s) {
        s.push_back(')');
        int n=s.size(),i=0;
        return solve(s,i,n);
    }
};