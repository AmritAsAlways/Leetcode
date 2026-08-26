class Solution {
public:
void check(string&ans,string&temp){
    if(ans==""){
        ans=temp;
        return;
    }

    int n=temp.size();
    for(int i=0;i<n;i++){
        if(temp[i]=='0' && ans[i]=='1'){
            ans=temp;
        }
        else if(temp[i]=='1' && ans[i]=='0') break;
    }
}
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size(),len=INT_MAX,i=0,j=0,ones=0;
        while(j<n){
            if(s[j]=='1') ones++;

            while(ones>k){
                if(s[i]=='1') ones--;
                i++;
            }
            while(ones==k){
                len=min(len,j-i+1);
                if(s[i]=='0') i++;
                else break;
            }
            
            j++;
        }
        if(len==INT_MAX) return "";

        i=0,j=0;
        string ans="",temp="";
        ones=0;
        while(j<len){
            temp+=s[j];
            if(s[j]=='1') ones++;
            j++;
        }
        if(ones==k) ans=temp;

        while(j<n){
            if(s[j]=='1') ones++;
            if(s[i]=='1') ones--;
            temp+=s[j];
            temp.erase(0,1);

            if(ones==k){
                check(ans,temp);
            }
            j++;
            i++;
        }

        return ans;
    }
};