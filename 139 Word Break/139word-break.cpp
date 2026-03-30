class Solution {
public:

    
   bool solve(string s, unordered_set<string>& st, vector<int>& dp) {
    if (s.size() == 0) return true;

    if (dp[s.size()] != -1) return dp[s.size()];

    for (int i = 1; i <= s.size(); i++) {
        string prefix = s.substr(0, i);

        if (st.find(prefix) != st.end()) {
            if (solve(s.substr(i), st, dp)) {
                return dp[s.size()] = 1;
            }
        }
    }

    return dp[s.size()] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size() + 1, -1);

    return solve(s, st, dp);
}
};