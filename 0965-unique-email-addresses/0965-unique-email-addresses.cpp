class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        unordered_set<string>us;
        for(int i=0;i<n;i++){
            string s="";
            bool check=true;
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='@'){
                    check=false;
                    s+=emails[i][j];
                }
                else if(emails[i][j]=='+' && check==true){
                    int k=j+1;
                    while(k<emails[i].size()){
                        if(emails[i][k]=='@') break;
                        k++;
                    }
                    j=k-1;
                }
                else if(emails[i][j]=='.' && check==true) check=true;
                else s+=emails[i][j];
            }
            us.insert(s);
        }
        return us.size();
    }
};