class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used; // 🔥 added

        for (int i = index; i < nums.size(); i++) {
            if (used.count(nums[i])) continue; // 🔥 skip duplicates

            used.insert(nums[i]); // 🔥 mark used

            swap(nums[index], nums[i]);
            solve(nums, index + 1);
            swap(nums[index], nums[i]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums, 0);
        return result;
    }
};