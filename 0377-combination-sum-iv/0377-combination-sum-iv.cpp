// class Solution {
// public:
//      void combination(vector<int>& nums,int target,vector<int>& ds,int &count){
//         if(target==0){
//             count++;
//             return;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>target) continue;
//         ds.push_back(nums[i]);
//         combination(nums,target-nums[i],ds,count);
//         ds.pop_back();
//         }  
//      }
//     int combinationSum4(vector<int>& nums, int target) {
//         //vector<vector<int>> ans;
//         vector<int>ds;
//         int count = 0;
//         combination(nums,target,ds,count);
//         return count;
        
        
        
//     }
// };
class Solution {
public:

    int combination(vector<int>& nums, int target,
                    vector<int>& dp) {

        if(target == 0)
            return 1;

        if(dp[target] != -1)
            return dp[target];

        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > target)
                continue;

            count += combination(nums, target - nums[i], dp);
        }

        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target + 1, -1);

        return combination(nums, target, dp);
    }
};