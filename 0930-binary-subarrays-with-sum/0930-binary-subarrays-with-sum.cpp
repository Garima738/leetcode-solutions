
class Solution {
public:
    bool isOne(int num) {
        return num == 1;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> nextone(n);
        int lastIndex = n;

        for (int i = n - 1; i >= 0; i--) {
            nextone[i] = lastIndex;

            if (isOne(nums[i])) {
                lastIndex = i;
            }
        }

        int i = 0, j = 0, sum = 0;
        int count = 0;

        while (j < n) {
            sum += nums[j];

            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            if (goal == 0) {
                if (sum == 0) {
                    count += j - i + 1;
                }
            } else {
                while (sum == goal && i <= j) {
                    count += nextone[j] - j;
                    sum -= nums[i];
                    i++;
                }
            }

            j++;
        }

        return count;
    }
};
