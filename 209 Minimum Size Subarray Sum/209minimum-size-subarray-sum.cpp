class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int right = 0;
        int n = nums.size();

        int minlen = INT_MAX;
        int sum = nums[0];

        while(right < n) {

            while(left <= right && sum >= target) {
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;

            if(right < n) {
                sum += nums[right];
            }
        }

        if(minlen == INT_MAX)
            return 0;

        return minlen;
    }
};