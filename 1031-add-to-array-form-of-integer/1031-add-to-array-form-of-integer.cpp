class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size(),i=0;
        reverse(num.begin(),num.end());
        int carry=0;
        while(i<n){
            int r=k%10;
            k/=10;

            int answer=num[i]+carry+r;
            num[i]=answer%10;
            answer/=10;
            carry=answer;
            i++;
        }
        cout<<k<<" "<<carry<<endl;
        while(k>0 || carry>0){
            int r=k%10;
            k/=10;

            int answer=r+carry;
            num.push_back(answer%10);
            carry=answer/10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};