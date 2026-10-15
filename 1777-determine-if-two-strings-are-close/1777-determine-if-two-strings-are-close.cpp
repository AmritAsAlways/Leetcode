class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int n=word1.size();

        //if there present a character which is only present in the one string and not another one
        vector<bool>charpresent1(26,false),charpresent2(26,false);
        for(int i=0;i<n;i++){
            charpresent1[word1[i]-'a']=true;
            charpresent2[word2[i]-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(charpresent1[i]!=charpresent2[i]) return false;
        }

        //for the number balances
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<n;i++){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<26;i++) if(v1[i]!=v2[i]) return false;

        return true;
    }
};