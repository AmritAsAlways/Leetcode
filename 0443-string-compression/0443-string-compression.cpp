class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size(),i=0;
        vector<char>v;
        while(i<n){
            char ch=chars[i];
            v.push_back(ch);
            int j=i,total=0;
            while(j<n){
                if(chars[j]!=chars[i]) break;
                total++;
                j++;
            }

            if(total!=1){
                string s=to_string(total);
                for(int j=0;j<s.size();j++){
                    v.push_back(s[j]);
                }
            }
            i=j;
        }
        chars=v;
        return v.size();
    }
};