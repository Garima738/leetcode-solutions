class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            sum = sum+nums[j];
            if(j-i+1<k){
                j++;
            }
          
            else if (j-i+1==k ){
                maxi = max(maxi,sum);
                sum = sum-nums[i];
               
                j++;
                i++;


            }
        }

        return double(maxi)/k;
    }
};
        
