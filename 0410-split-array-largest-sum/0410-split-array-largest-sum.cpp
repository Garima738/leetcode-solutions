class Solution {
public:

    int maxelement(vector<int>& nums) {
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    long long sumarray(vector<int>& nums) {
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return sum;
    }

    bool canSplit(vector<int>& nums, long long maxSum, int k) {

        int subarrays = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(sum + nums[i] > maxSum) {
                subarrays++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }

            if(subarrays > k)
                return false;
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = maxelement(nums);
        long long high = sumarray(nums);
        long long ans = -1;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(canSplit(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};