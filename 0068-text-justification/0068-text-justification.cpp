class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(),i=0;
        vector<string>v;
        while(i<n){
            int j=i+1,totallen=words[i].size(),count=1;
            string s=words[i];
            while(j<n){
                if(totallen+1+words[j].size()>maxWidth) break;
                totallen+=1+words[j].size();
                count++;
                j++;
            }
            cout<<i<<" "<<j<<" "<<count<<" "<<s<<endl;
            if(count==1){
                int totalsize=words[i].size();
                while(totalsize<maxWidth){
                    s+=" ";
                    totalsize++;
                }
            }
            else if(j==n){
                int totalsize=words[i].size(),k=i+1;
                while(k<j){
                    s+=" ";
                    s+=words[k];
                    totalsize+=1+words[k].size();
                    k++;
                }
                while(totalsize<maxWidth){
                    s+=" ";
                    totalsize++;
                }
            }
            else{
                count--;
                int diff=maxWidth-totallen;
                int extra=diff/count,remainder=diff%count,k=i+1;
                while(k<j){
                    int z=0;
                    while(z<extra){
                        s+=" ";
                        z++;
                    }
                    s+=" ";
                    if(remainder>0){
                        s+=" ";
                        remainder--;
                    }
                    s+=words[k];
                    k++;
                }
            }
            cout<<s<<endl;
            v.push_back(s);
            i=j;
        }
        return v;
    }
};