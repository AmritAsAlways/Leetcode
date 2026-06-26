class Solution {
public:
    long long minEnd(int n, int x) {
        int num=x,bits=0,setbits=0;
        vector<int>v;
        while(num>0){
            int r=num%2;
            num/=2;
            bits++;
            v.push_back(r);
            if(r==1) setbits++;
        }
        int zerobits=bits-setbits;
        n--;
        vector<int>temp;
        while(n>0){
            int r=n%2;
            n/=2;
            temp.push_back(r);
        }
        n=v.size();
        int m=temp.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(v[i]==1){
                i++;
                continue;
            }

            v[i]=temp[j];
            i++;
            j++;
        }
        while(j<m){
            v.push_back(temp[j]);
            j++;
        }
        long long answer=0;
        i=0;
        n=v.size();
        while(i<n){
            answer+=v[i]*pow(2,i);
            i++;
        }
        return answer;
    }
};