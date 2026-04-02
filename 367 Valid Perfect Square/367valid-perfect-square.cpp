class Solution {
public:
    bool isPerfectSquare(int num) {
        int x=num;

    if(x == 0 || x == 1) return x;
    
    int start = 1, end = x, ans = 0;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(mid <= x / mid) { 
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans*ans==num ;
}

};
 