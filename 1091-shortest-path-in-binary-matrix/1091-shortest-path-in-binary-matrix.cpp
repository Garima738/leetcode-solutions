class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;
        }

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) {
                return d;
            }

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 &&
                    d + 1 < dist[newr][newc]) {

                    dist[newr][newc] = d + 1;
                    q.push({d + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};