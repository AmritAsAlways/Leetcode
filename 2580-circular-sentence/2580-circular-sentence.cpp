class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size(),i=0;
        char last=' ';
        while(i<n){
            if(sentence[i]==' ') break;
            last=sentence[i];
            i++;
        }
        i++;
        while(i<n){
            char first=sentence[i];
            if(first!=last) return false;
            while(i<n){
                if(sentence[i]==' ') break;
                last=sentence[i];
                i++;
            }
            i++;
        }
        if(sentence[0]!=sentence[n-1]) return false;
        return true;
    }
};