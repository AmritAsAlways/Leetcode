class Solution {
public:
int dp[1001][1001];
    int solve(string &text1, string &text2, int idx, int i) {
        int n = text1.size(), m = text2.size();
        // base condition
        if (idx == n || i == m) return dp[idx][i]=0;

        if(dp[idx][i]!=-1) return dp[idx][i];

        int x=0,y=0;
        if(text1[idx]==text2[i]){
            x=1+solve(text1,text2,idx+1,i+1);
        }
        else{
            y=max(solve(text1,text2,idx+1,i),solve(text1,text2,idx,i+1));
        }

        return dp[idx][i]=max(x,y);;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        // int answer = 0;

        //all those cases we want to cover by this are already covered in skip the character 
        //logic


        // for (int i = 0; i < n; i++) {
        //     answer = max(answer, solve(text1, text2, i, 0));
        // }


        // return answer;
        memset(dp,-1,sizeof(dp));

        solve(text1,text2,0,0);
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                cout<<dp[i][j];
            }
            cout<<endl;
        }

        return dp[0][0];
    }
};
