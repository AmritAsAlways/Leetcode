class Solution {
public:
// void solve(string&s,int&k,vector<vector<int>>&ispalindrome,int&answer,int total,int  index,int&n){
//     if(index==n){
//         answer=max(answer,total-1);
//         return;
//     }

//     for(int i=index;i<n;i++){
//         for(int j=i+k-1;j<n;j++){
//             if(ispalindrome[i][j]){
//                 solve(s,k,ispalindrome,answer,total+1,j+1,n);
//             }
//         }
//     }

// }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<int>>ispalindrome(n,vector<int>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    ispalindrome[i][j]=true;
                    continue;
                }

                if(s[i]==s[j]){
                    if(j-i==1 || ispalindrome[i+1][j-1]) ispalindrome[i][j]=true; 
                }
            }
        }

        //wrong idea and wrong solution

        // int answer=0;
        // for(int i=0;i<n;i++){
        //     int j=i+k-1;
        //     while(j<n){
        //         if(ispalindrome[i][j]){
        //             solve(s,k,ispalindrome,answer,1,j+1,n);
        //         }
        //         j++;
        //     }
        // }
        // return answer;

        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int answer=0;
            answer=dp[i+1];

            for(int j=i+k-1;j<n;j++){
                if(ispalindrome[i][j]){
                    answer=max(answer,1+dp[j+1]);
                }
            }

            dp[i]=answer;
        }
        return dp[0];
    }
};