class Solution {
public:
    int smallestNumber(int n, int t) {
         while (true) {
            long long product = digitproduct(n);

            if (product % t == 0)
                return n;

            n++;
        }

        return -1;
    }
        
    
    long long digitproduct(long n){
        long long product = 1;
        while(n>0){
            int digit = n%10;
            product *=digit;
            n = n/10;
        }
        return product;
    }
};