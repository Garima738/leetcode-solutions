class Solution {
public:

     int maxelement(vector<int>& nums){
        int n= nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
     }
     
     int diviso(vector<int>& nums,int divisors){
        int divisor = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            divisor+= ceil(double(nums[i])/divisors);
        }
        return divisor;
     }

     
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int ans = 1;
        int high = maxelement(nums);
        while(low<=high){
            int  mid = (low+high)/2;
            int divisor = diviso(nums,mid);
            if(divisor<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;

        
    }
};