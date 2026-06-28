class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        int n=v.size();
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
        num=0;
        for(int i=n-1;i>0;i--){
            int maxi=-1,index=-1;
            for(int j=i-1;j>=0;j--){
                if(v[j]>v[i] && v[j]>=maxi){
                    index=j;
                    maxi=v[j];
                }
            }

            if(index!=-1){
                swap(v[i],v[index]);
                break;
            }
        }
        for(int i=0;i<n;i++){
            num+=pow(10,i)*v[i];
        }
        return num;
    }
};