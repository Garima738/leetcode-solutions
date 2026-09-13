class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = n;
        if(nn<0) {
            x = 1/x;
            nn = -nn;
        }
        while(nn){
            if(nn%2==1){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        return ans;
        
    }
};