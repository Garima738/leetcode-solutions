class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n= nums.size();
      int i=0;
      int sum=0;
      int digitSum=0;
        for(int i=0;i<n;i++){
              
            sum +=nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 0) {
                digitSum += x % 10;
                x /= 10;
            }
        }

       
        return abs(sum - digitSum);
    }
    };