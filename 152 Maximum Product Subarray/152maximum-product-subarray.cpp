class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxproduct = nums[0];
        int minproduct = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            int temp = maxproduct;

            maxproduct = max({nums[i], nums[i]*maxproduct, nums[i]*minproduct});
            minproduct = min({nums[i], nums[i]*temp, nums[i]*minproduct});

            ans = max(ans, maxproduct);
        }

        return ans;
    }
};