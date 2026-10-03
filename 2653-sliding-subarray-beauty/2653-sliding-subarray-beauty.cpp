class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int n = nums.size();
        int i = 0;
        int j = 0;

        vector<int> ans;

        int freq[50] = {0};

        while (j < n) {

            // Add nums[j] to the window
            if (nums[j] < 0) {
                freq[nums[j] + 50]++;
            }

            if (j - i + 1 < k) {
                j++;
            }

            else if (j - i + 1 == k) {

                int count = 0;
                int beauty = 0;

                // Find x-th smallest negative number
                for (int p = 0; p < 50; p++) {

                    count += freq[p];

                    if (count >= x) {
                        beauty = p - 50;
                        break;
                    }
                }

                ans.push_back(beauty);

                if (nums[i] < 0) {
                    freq[nums[i] + 50]--;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};