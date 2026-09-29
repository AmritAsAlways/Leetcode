class Solution {
public:
string add(string s,string t){
    int n=s.size(),m=t.size(),i=n-1,j=m-1;
    int carry=0;
    string ans="";
    while(i>=0 && j>=0){
        int num1=s[i]-'0',num2=t[j]-'0';
        int total=num1+num2+carry;
        char ch=total%10+'0';
        ans=ch+ans;
        total/=10;
        carry=total;
        i--;
        j--;
    }
    cout<<s<<" "<<t<<" "<<ans<<" ";
    while(i>=0){
        int num1=s[i]-'0';
        int total=num1+carry;
        char ch=total%10+'0';
        ans=ch+ans;
        total/=10;
        carry=total;      
        i--;
    }
    while(j>=0){
        int num1=t[j]-'0';
        int total=num1+carry;
        char ch=total%10+'0';
        ans=ch+ans;
        total/=10;
        carry=total;      
        j--;
    }
    cout<<ans<<endl;
    if(carry!=0){
        char ch=carry+'0';
        ans=ch+ans;
    }
    return ans;
}
bool check(string num,int idx,string first,string second){
    int n=num.size();
    if(idx==n) return true;

    string total=add(first,second);

    string number="";
    if(num[idx]=='0'){
        int i=idx;
        while(i<n){
            if(num[i]!='0') break;
            number+=num[i];
            i++;
        }
        if(number==total && check(num,i,second,number)) return true;
    }
    else{
        for(int i=idx;i<n;i++){
            number+=num[i];
            if(number==total && check(num,i+1,second,number)) return true;
        }
    }

    return false;
}
bool secondnumber(string num,int idx,string first){
    int n=num.size();
    string second="";
    if(num[idx]=='0'){
        int j=idx;
        while(j<n-1){
            if(num[j]!='0') break;
            if(check(num,j,first,second)) return true;
            j++;
        }
        if(check(num,j,first,second)) return true;
    }
    else{
        for(int j=idx;j<n-1;j++){
            second+=num[j];
            if(check(num,j+1,first,second)) return true;
        }
    }
    return false;
}
    bool isAdditiveNumber(string num) {
        int n=num.size();
        if(n<3) return false;
        string first="";

        if(num[0]=='0'){
            int i=0;
            while(i<n-2){
                if(num[i]!='0') break;
                if(secondnumber(num,i,"0")) return true;
                i++;
            }
            if(secondnumber(num,i,"0")) return true;
        }
        else{
            for(int i=0;i<n-2;i++){
                first+=num[i];
                if(secondnumber(num,i+1,first)) return true;
            }
        }
        return false;
    }
};