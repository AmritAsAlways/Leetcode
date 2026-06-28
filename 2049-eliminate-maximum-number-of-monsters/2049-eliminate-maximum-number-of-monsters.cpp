class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double>time(n,0);
        for(int i=0;i<n;i++){
            time[i]=(double)dist[i]/(double)speed[i];
        }
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++) cout<<time[i]<<" ";
        cout<<endl;
        double t=0,i=0;
        while(i<n){
            //use the sword
            cout<<time[i]<<" "<<t<<endl;
            if(time[i]<=t){
                cout<<time[i]<<" "<<t<<endl;
                return i;
            }
            i++;
            t++;
        }
        return n;
    }
};