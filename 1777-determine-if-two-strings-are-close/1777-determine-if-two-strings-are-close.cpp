class Solution {
public:
void changenumber(char ch1,char ch2,int index,int&n,string&word){
    for(int i=index;i<n;i++){
        if(word[i]==ch1){
            word[i]=ch2;
        }
        else if(word[i]==ch2){
            word[i]=ch1;
        }
    }
}
bool solve(char ch1,char ch2,string&word1,string&word2,int index,int&n,vector<bool>&orientation){
    for(int i=index;i<n;i++){
        if(word1[i]==ch2 && word2[i]==ch1){
            word1[i]=ch1;
            word2[i]=ch2;
            orientation[i]=true;
            return true;
        }
    }
    return false;
}
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

        // vector<int>second(26,0);
        // vector<bool>numberchanged(26,false);
        // vector<bool>orientationchanged(n,false);
        // for(int i=0;i<n;i++) second[word2[i]-'a']++;
        // bool answer=true;
        // for(int i=0;i<n;i++){
        //     if(orientationchanged[i]==true) continue;
        //     if(word2[i]==word1[i]){
        //         numberchanged[word2[i]-'a']=true;
        //         continue;
        //     }

        //     char ch1=word1[i],ch2=word2[i];
        //     //if either of ch1 or ch2 'numbers (or in other words if ch1 or ch2 has already came before this index so we cannot go and change before we can only change the orientation of string now ) in word2 is numberchanged before then we can only change the orientation
        //     if(numberchanged[word1[i]-'a']==true || numberchanged[word2[i]-'a']==true){
        //         if(solve(ch1,ch2,word1,word2,i,n,orientationchanged)==false){
        //             answer=false;
        //             break;
        //         }
        //     }
        //     else{
        //         changenumber(ch1,ch2,i,n,word2);
        //         numberchanged[ch1-'a']=true;
        //     }
        // }
        // if(answer==true) return true;
        // answer=true;
        // for(int i=0;i<n;i++) orientationchanged[i]=false;
        // for(int i=0;i<26;i++) numberchanged[i]=false;
        // for(int i=0;i<n;i++){
        //     if(orientationchanged[i]==true) continue;
        //     if(word2[i]==word1[i]){
        //         numberchanged[word2[i]-'a']=true;
        //         continue;
        //     }
        //     char ch1=word1[i],ch2=word2[i];
        //     if(solve(ch1,ch2,word1,word2,i,n,orientationchanged)){
        //         numberchanged[ch1-'a']=true;
        //         numberchanged[ch2-'a']=true;
        //         continue;
        //     }

        //     if(numberchanged[ch1-'a']==true && numberchanged[ch2-'a']==true) return false;
        //     changenumber(ch1,ch2,i,n,word2);
        //     numberchanged[ch1-'a']=true;
        // }
        // return answer;
    }
};