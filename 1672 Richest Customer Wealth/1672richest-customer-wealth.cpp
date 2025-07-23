class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth=0;
        for(int row=0;row<accounts.size();row++){
            int sum=0;
            for(int cols=0;cols<accounts[row].size();cols++){
                sum=sum+accounts[row][cols];


            }
            if (sum > maxWealth) {
         maxWealth = sum;
}



        }return maxWealth;
        
    }
};