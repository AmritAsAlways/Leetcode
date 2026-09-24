class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int n=A.size();
        unordered_map<int,int>us;
        int answer=INT_MAX;
        for(int i=1;i<n;i++){
            A[i]+=A[i-1];
            us[A[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(A[i]==x){
                answer=min(i+1,answer);
                break;
            }
            if(A[i]>x) break;
            us.erase(A[i]);

            int findvalue=x-A[i];
            if(us.find(A[n-1]-findvalue)!=us.end()){
                int index=us[A[n-1]-findvalue];
                cout<<i+1<<" "<<n-1-index<<endl;
                cout<<i+1+n-1-index<<"endl"<<endl;
                answer=min(answer,i+1+n-1-index);
            }
        }
        cout<<endl;
        for(int i=n-1;i>=0;i--){
            if(A[i]==A[n-1]-x){
                cout<<n-1-i<<endl;
                answer=min(answer,n-1-i);
                break;
            }
        }
        return (answer==INT_MAX) ? -1 : answer;
    }
};