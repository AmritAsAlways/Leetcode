class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        if(n==1){
            if(s1[0]=='1' && s2[0]=='0') return -1;
            if(s1[0]==s2[0]) return 0;
            return 1;
        } 
        int operation=0;
        char prevs1='/',prevs2='/',lasts1=s1[n-1],lasts2=s2[n-1];
        int prev=0;
        for(int i=0;i<n-1;i++){
            prevs1=s1[i];
            prevs2=s2[i];
            if(s1[i]==s2[i]){
                prev=0;
            }
            else if(s1[i]=='0'){
                prev=1;
                operation++;
            }
            else if(s1[i]=='1' && s1[i+1]=='1'){
                s1[0]='0';
                s1[i+1]='0';
                operation++;
                prev=1;
            }
            else if(s1[i]=='1' && s1[i+1]=='0'){
                s1[0]='0';
                s1[i+1]='0';
                operation+=2;
                prev=2;
            }
        }
        cout<<operation<<" "<<prev<<endl;
        if(s1[n-1]==s2[n-1]) return operation;
        if(s1[n-1]=='0'){
            operation++;
            return operation;
        }
        operation-=prev;
        if(prevs1=='0' && lasts1=='0'){
            if(prevs2=='0' && lasts2=='1') operation++;
            if(prevs2=='1' && lasts2=='0') operation++;
            if(prevs2=='1' && lasts2=='1') operation+=2;
        }
        if(prevs1=='0' && lasts1=='1'){
            if(prevs2=='0' && lasts2=='0') operation+=2;
            if(prevs2=='1' && lasts2=='0') operation+=3;
            if(prevs2=='1' && lasts2=='1') operation++;
        }
        if(prevs1=='1' && lasts1=='0'){
            if(prevs2=='0' && lasts2=='1') operation++;
            if(prevs2=='0' && lasts2=='0') operation+=2;
            if(prevs2=='1' && lasts2=='1') operation++;
        }
        if(prevs1=='1' && lasts1=='1'){
            if(prevs2=='0' && lasts2=='1') operation+=2;
            if(prevs2=='1' && lasts2=='0') operation+=2;
            if(prevs2=='0' && lasts2=='0') operation++;
        }
        return operation;
    }
};