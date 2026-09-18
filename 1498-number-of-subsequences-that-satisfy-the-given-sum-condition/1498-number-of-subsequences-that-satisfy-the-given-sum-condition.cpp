class Solution {
public:
    int mod = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Calculate 2^0, 2^1, 2^2, ... once
        vector<long long> power(n);

        power[0] = 1;

        for(int k = 1; k < n; k++) {
            power[k] = (power[k - 1] * 2) % mod;
        }

        long long result = 0;

        int i = 0;
        int j = n - 1;

        while(i <= j) {

            if(nums[i] + nums[j] <= target) {

                result = (result + power[j - i]) % mod;

                i++;
            }
            else {
                j--;
            }
        }

        return result;
    }
};
//   int result = 0;

//     int maxi(vector<int>& nums) {
//         int n = nums.size();
//         int maximum = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] > maximum) {
//                 maximum = nums[i];
//             }
//         }

//         return maximum;
//     }

//     int mini(vector<int>& nums) {
//         int n = nums.size();
//         int minimum = INT_MAX;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] < minimum) {
//                 minimum = nums[i];
//             }
//         }

//         return minimum;
//     }

//     void solve(int idx, vector<int>& nums, vector<int>& arr, int target) {

//         if (idx == nums.size()) {

//             if (arr.empty())
//                 return;

//             int minimum = mini(arr);
//             int maximum = maxi(arr);

//             if (minimum + maximum <= target) {
//                 result++;
//             }

//             return;
//         }

        
//         arr.push_back(nums[idx]);
//         solve(idx + 1, nums, arr, target);

//         arr.pop_back();

//         solve(idx + 1, nums, arr, target);
//     }

//     int numSubseq(vector<int>& nums, int target) {

//         vector<int> arr;

//         solve(0, nums, arr, target);

//         return result;