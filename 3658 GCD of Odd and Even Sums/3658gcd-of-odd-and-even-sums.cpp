class Solution {
public:
    int evensum(int n) {
        int sum = 0;
         for(int i = 2; i <= 2*n; i += 2) {
            sum += i;
        }

        return sum;
    }

    int oddsum(int n) {
        int sum = 0;

        for(int i = 1; i <= 2*n; i += 2) {
            sum += i;
        }

        return sum;
    }

    int gcdOfOddEvenSums(int n) {
        int even = evensum(n);
        int odd = oddsum(n);

        return gcd(even, odd);
    }
};