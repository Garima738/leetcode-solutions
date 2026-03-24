class Solution {
public:
    int mincost(vector<int>& cuts, int left, int right, vector<vector<int>>& dp) {
    
        if (right - left <= 1) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX;
        for (int k = left + 1; k < right; k++) {
            int cost = (cuts[right] - cuts[left]) 
                     + mincost(cuts, left, k, dp) 
                     + mincost(cuts, k, right, dp);

            ans = min(ans, cost);
        }

        return dp[left][right] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
         vector<vector<int>> dp(m, vector<int>(m, -1));
         return mincost(cuts, 0, m - 1, dp);
    }
};