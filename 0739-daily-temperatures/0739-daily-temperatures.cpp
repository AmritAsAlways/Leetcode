class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
                st.push(i);
                continue;
            }
            bool choosed=false;
            while(!st.empty()){
                int idx=st.top();

                if(temperatures[idx]>temperatures[i]){
                    ans[i]=idx-i;
                    choosed=true;
                    break;
                }
                st.pop();
            }
            st.push(i);
            if(!choosed) ans[i]=0;
        }
        return ans;
    }
};