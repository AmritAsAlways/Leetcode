class Solution {
public:
    int minimumPushes(string word) {
        int answer=0,n=word.size();
        int ones=8,second=8,third=8,fourth=2;
        vector<int>v(26,0);
        for(int i=0;i<n;i++) v[word[i]-'a']++;
        sort(v.begin(),v.end());
        for(int i=25;i>=0;i--) cout<<v[i]<<" "<<endl;
        int j=25;
        while(j>=0){
            if(v[j]==0) break;
            int value=v[j];
            if(ones>0){
                answer+=value;
                ones--;
            }
            else if(second>0){
                answer+=value*2;
                second--;
            }
            else if(third>0){
                answer+=value*3;
                third--;
            }
            else if(fourth>0){
                answer+=value*4;
                fourth--;
            }
            j--;
        }
        return answer;
    }
};