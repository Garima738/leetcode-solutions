class Solution {
public:
    long long sumAndMultiply(int n) {
      long long sum = 0;
        long long x = 0;
        long long place = 1;

        while(n > 0){
            int digit = n % 10;

            if(digit != 0){
                sum += digit;
                x = digit * place + x;   
                place *= 10;
            }

            n = n / 10;
        }

        return sum * x;
    }
};