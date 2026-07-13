class Solution {
public:
int solve(string&a){
    int hr=10*(a[0]-'0')+(a[1]-'0');
    int min=10*(a[3]-'0')+(a[4]-'0');
    int second=10*(a[6]-'0')+(a[7]-'0');
    return hr*3600+min*60+second;
}
    int secondsBetweenTimes(string startTime, string endTime) {
        int startseconds=solve(startTime),endseconds=solve(endTime);
        return endseconds-startseconds;
    }
};