class Solution {
public:
    int totalNumbers(auto& digits) {
        int n=digits.size();
        vector<int>dig(10,0);
        for(int i=0;i<n;i++) dig[digits[i]]++;
        unordered_set<int>us;
        for(int i=0;i<10;i++){
            if(dig[i]<=0) continue;
            int sum=0;
            sum*=10;
            sum+=i;
            dig[i]--;
            for(int j=0;j<10;j++){
                if(dig[j]<=0) continue;

                sum*=10;
                sum+=j;
                dig[j]--;
                for(int k=0;k<10;k++){
                    if(dig[k]<=0 || k%2!=0) continue;

                    sum*=10;
                    sum+=k;
                    dig[k]--;

                    if(sum<1000 && sum>99){
                        us.insert(sum);
                    }

                    dig[k]++;
                    sum-=k;
                    sum/=10;
                }

                dig[j]++;
                sum-=j;
                sum/=10;
            }
            dig[i]++;
            sum-=i;
            sum/=10;
        }
        return us.size();
    }
};