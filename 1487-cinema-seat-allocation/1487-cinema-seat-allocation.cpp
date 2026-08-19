class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size(), answer = 0;
        sort(reservedSeats.begin(), reservedSeats.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int prevanswer = 2 * (reservedSeats[0][0] - 1);
        int i=0;
        while (i < m) {
            int row = reservedSeats[i][0];
            vector<int> v(11, 0);
            while (i < m && reservedSeats[i][0] == row) {
                v[reservedSeats[i][1]]++;
                i++;
            }
            for (int j = 2; j <= 10; j++) {
                v[j] += v[j - 1];
            }

            if (v[5] - v[1] == 0) {
                answer++;
                if (v[9] - v[5] == 0)
                    answer++;
            } else if (v[7] - v[3] == 0) {
                answer++;
            } else if (v[9] - v[5] == 0) {
                answer++;
            }
            int lastrow=n,firstrow=reservedSeats[i-1][0]+1;
            if(i!=m) lastrow=reservedSeats[i][0]-1;
            int intervalanswer=2*(lastrow-firstrow+1);
            answer+=intervalanswer;
        }
        answer+=prevanswer;
        return answer;
    }
};