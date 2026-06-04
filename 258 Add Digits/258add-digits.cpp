class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {             
            int sum = 0;
            while (num > 0) {  
                int n=num%10;         
                sum += n;        
                num /= 10;              
            }
            num = sum;                  
        }
        return num;
    }
};
