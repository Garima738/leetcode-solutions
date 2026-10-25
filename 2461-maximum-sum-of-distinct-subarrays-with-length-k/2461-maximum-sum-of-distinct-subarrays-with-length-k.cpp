class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, maxi = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mp;

        while (j < n) {
            sum += nums[j];
            mp[nums[j]]++;

            if (j - i + 1 < k) {
                j++;
            }
            else {
                if (mp.size() == k) {
                    maxi = max(maxi, sum);
                }

                sum -= nums[i];
                mp[nums[i]]--;

                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                i++;
                j++;
            }
        }

        return maxi;
    }
};