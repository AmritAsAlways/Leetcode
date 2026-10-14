class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        vector<int>first(26,0),second(26,0);
        for(int i=0;i<n;i++){
            first[s1[i]-'a']++;
            second[s2[i]-'a']++;
        }
        //check if string s1 can break s2
        int i=0,j=0,another=second[j];
        bool answer=true;
        while(i<26){
            if(first[i]==0){
                i++;
                continue;
            }

            int times=first[i];
            while(times>0){
                if(i<j){
                    answer=false;
                    break;
                }

                if(another==0){
                    j++;
                    another=second[j];
                    continue;
                }

                times--;
                another--;
            }

            if(answer==false) break;
            i++;
        }
        if(answer) return true;
        
        i=0,j=0,another=first[i];
        answer=true;
        while(j<26){
            if(second[j]==0){
                j++;
                continue;
            }

            int times=second[j];
            while(times>0){
                if(j<i){
                    answer=false;
                    break;
                }

                if(another==0){
                    i++;
                    another=first[i];
                    continue;
                }
                times--;
                another--;
            }

            if(answer==false) break;
            j++;        
        }
        return (answer==true) ? true : false;
    }
};