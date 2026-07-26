// class Solution {
// public:
//  int nCr(int n, int r) {
//         long long ans = 1;

//         for (int i = 0; i < r; i++) {
//             ans = ans * (n - i);
//             ans = ans / (i + 1);
//         }

//         return ans;
//     }
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>>ans;
//         for(int row=0;row<numRows;row++){
//             vector<int>temp;
//             for(int col=0;col<=row;col++){
//                 temp.push_back(nCr(row,col));
//             }
//             ans.push_back(temp);
//         }
//         return ans;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int row = 0; row < numRows; row++) {
            vector<int> temp;
            long long val = 1;

            temp.push_back(1);

            for (int col = 1; col <= row; col++) {
                val = val * (row - col + 1);
                val = val / col;
                temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
