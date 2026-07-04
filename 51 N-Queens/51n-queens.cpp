class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag1(2*n - 1, 0);     // row + col
        vector<int> diag2(2*n - 1, 0);     // row - col + n - 1

        solve(0, n, board, ans, col, diag1, diag2);
        return ans;
    }

    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& col,
               vector<int>& diag1,
               vector<int>& diag2) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(col[c] == 0 && diag1[row + c] == 0 && diag2[row - c + n - 1] == 0) {

                // place queen
                board[row][c] = 'Q';
                col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

                solve(row + 1, n, board, ans, col, diag1, diag2);

                // backtrack
                board[row][c] = '.';
                col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
            }
        }
    }
};