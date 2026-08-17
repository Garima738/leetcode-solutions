class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double half = myPow(x, N / 2);
        double result = half * half;

        if (N % 2 == 1) {
            result = x * result;
        }

        return result;
    }
};