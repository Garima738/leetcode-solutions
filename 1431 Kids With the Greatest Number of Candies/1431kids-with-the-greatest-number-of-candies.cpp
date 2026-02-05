class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> list;

        for (int i = 0; i < candies.size(); i++) {
            bool flag = true;
            int maxCandie = candies[i] + extraCandies;

            for (int j = 0; j < candies.size(); j++) {
                if (candies[j] > maxCandie) {
                    flag = false;
                    break;
                }
            }
            list.push_back(flag);
        }
        return list;
    }
};
