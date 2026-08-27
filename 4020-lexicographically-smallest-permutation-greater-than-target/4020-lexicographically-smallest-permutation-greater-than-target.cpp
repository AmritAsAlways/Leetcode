class Solution {
public:
    bool solve(vector<int>&v,string&target,string temp,string&answer,int idx,int&n){
        //base condition 
        if(idx==n){
            if(temp==target) return false;
            answer=temp;
            return true;
        }
        int x=target[idx]-'a';

        while(x<26){
            if(v[x]==0){
                x++;
                continue;
            }

            temp.push_back(x+'a');
            v[x]--;

            if(x>target[idx]-'a'){
                answer=temp;
                return true;
            }
            if(solve(v,target,temp,answer,idx+1,n)) return true;
            v[x]++;
            temp.pop_back();
            x++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        string answer="";
        bool check=solve(v,target,"",answer,0,n);
        
        if(check){
            if(answer.size()==n) return answer;

            for(int i=0;i<26;i++){
                int x=v[i];
                while(x>0){
                    answer+='a'+i;
                    x--;
                }
            }
        }

        return answer;
    }
};