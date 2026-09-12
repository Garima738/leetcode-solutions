class Solution {
public:
    bool isPalindrome(int x) {
       long n = x;
       long rev=0,rem=0;
       if(n<0) return false;
       while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;

       }
       if(x==rev){
        return true;
       }
       return false;}
};