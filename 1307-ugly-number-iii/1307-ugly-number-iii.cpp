class Solution {
public:
int solve(long long mid,long long a,long long b,long long c){
    long long answer=0;
    //number divisible by a upto mid
    answer+=(mid)/a;
    //number divisible by b upto mid
    answer+=(mid)/b;
    //number divisible by c upto mid
    answer+=(mid)/c;
    //number divisible by (a*b) upto mid
    long long d=lcm(a,b);
    answer-=(mid)/d;
    //number divisible by (a*c) upto mid
    long long e=lcm(b,c);
    answer-=(mid)/e;
    //number divisible by (b*c) upto mid
    long long f=lcm(a,c);
    answer-=(mid)/f;
    //number divisible by (a*b*c) upto mid
    long long g=lcm(d,c);
    answer+=mid/g;
    return answer;
}
    int nthUglyNumber(int n, int a, int b, int c) {
        //the smallest ugly number is a and largest is some number i donot know so INT_MAX
        long long small=min({a,b,c}),largest=INT_MAX;
        long long solution=-1;
        while(small<=largest){
            long long mid=small+(largest-small)/2;

            long long answer=solve(mid,a,b,c);

            if(answer>=n){
                solution=mid;
                largest=mid-1;
            }
            else{
                small=mid+1;
            }
        }
        return solution;
    }
};
