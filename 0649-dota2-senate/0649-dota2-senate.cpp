class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size(),r=0,d=0;
        deque<char>dq;
        for(int i=0;i<n;i++){
            dq.push_back(senate[i]);
        }
        int count=0;;
        while(!dq.empty()){
            char ch=dq.front();
            dq.pop_front();
            count++;
            if(ch=='R' && r<0){
                r++;
                count=0;
                continue;
            }
            if(ch=='D' && d<0){
                d++;
                count=0;
                continue;
            }

            if(ch=='R') d--;
            if(ch=='D') r--;


            dq.push_back(ch);
            if(count==dq.size()) break;
        }
        return (dq.front()=='R') ? "Radiant" : "Dire";




    }
};