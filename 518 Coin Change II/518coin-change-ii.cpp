class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //return count(amount, coins, 0);
        vector<unsigned int> dp(amount+1, 0);
        dp[0]=1;
        for(auto coin: coins){
            if(coin > amount){
                continue;
            }
            for(auto c = coin; c<=amount;c++){
                dp[c] += dp[c-coin];
            }
        }
        return (int)dp[amount];
    }
};