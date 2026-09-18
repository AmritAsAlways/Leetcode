class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),changes=0,idx1=-1,idx2=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                changes++;
                if(changes>2) return false;
                if(idx1==-1) idx1=i;
                else idx2=i;
            }
        }
        if(idx1==idx2 && idx1==-1) return true;
        if(idx2==-1) return false;
        return (s2[idx2]==s1[idx1] && s1[idx2]==s2[idx1]) ? true : false;
    }
};