class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),answer=0;
        for(int r=0;r<n;r++){

            for(int c=0;c<n;c++){
                bool check=true;
                int col=0;
                for(int k=0;k<n;k++){
                    if(grid[r][col]!=grid[k][c]){
                        check=false;
                        break;
                    }
                    col++;
                }

                if(check) answer++;
            }

        }
        return answer;
    }
};