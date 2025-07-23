class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum;
        int running=0;
        for(int i=0;i<n;i++){
            running+=nums[i];
            sum.push_back(running);
        }
        return sum;
    }
};