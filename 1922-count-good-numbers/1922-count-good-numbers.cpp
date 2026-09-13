class Solution {
public:
     int M = 1e9+7;
   int findpower(long long a,long long b){
    if(b==0) return 1;
    int half = findpower(a,b/2);
    long long result = (1LL*half * half) % M;
    if(b%2==1){
        result = (result*a)%M;


    }
    return result;
   }
    int countGoodNumbers(long long n) {
        return (1LL*findpower(5,(n+1)/2)*findpower(4,(n/2)))%M;
      
        
    }
};