class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<pair<char,int>>v(26,{'a',0});
        for(int i=0;i<26;i++) v[i].first='a'+i;
        for(int i=0;i<n;i++) v[s[i]-'a'].second++;
        sort(v.begin(),v.end(),[](const pair<char,int>&a,const pair<char,int>&b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        int i=0,j=25;
        while(i<26){
            if(v[i].second!=0) break;
            i++;
        }
        string ans1="";
        //only one character is present 
        if(i==j){
            if(v[i].second==1){
                ans1+=v[i].first;
            }
            return ans1;
        } 
        while(i<j){
            char ch1=v[i].first,ch2=v[j].first;
            ans1+=ch1;
            ans1+=ch2;
            v[i].second--;
            v[j].second--;
            if(v[i].second==0) i++;
            if(v[j].second==0) j--;
        }
        if(i>j) return ans1;
        string ans2="";
        int k=0,m=ans1.size();
        if(ans1[0]!=v[i].first){
            v[i].second--;
            ans2+=v[i].first;
        }
        while(v[i].second>0 && k<m-1){
            if(v[i].first!=ans1[k] && v[i].first!=ans1[k+1]){
                ans2+=ans1[k];
                ans2+=v[i].first;
                k++;
                v[i].second--;
            }
            else{
                ans2+=ans1[k];
                k++;
            }
        }
        if(v[i].second==0){
            while(k<m){
                ans2+=ans1[k];
                k++;
            }
            return ans2;
        }
        cout<<v[i].second<<endl;
        if(k==m-1 && v[i].second>2) return "";
        if(k==m-1 && v[i].second==1){
            if(v[i].first==ans1[k]) return "";
            if(ans2[ans2.size()-1]==ans1[k]){
                ans2+=v[i].first;
                ans2+=ans1;
            }
            else{
                ans2+=ans1;
                ans2+=v[i].first;
            }
            return ans2;
        }
        cout<<"afa"<<ans2<<endl;
        if(k==m-1 && v[i].second==2){
            int z=ans2.size();
            if(ans2[z-1]!=v[i].first && ans1[k]!=v[i].first){
                ans2+=v[i].first;
                ans2+=ans1[k];
                ans2+=v[i].first;
                return ans2;
            }
            else{
                return "";
            }
        }
        cout<<ans2<<endl;
        return ans2;
    }
};