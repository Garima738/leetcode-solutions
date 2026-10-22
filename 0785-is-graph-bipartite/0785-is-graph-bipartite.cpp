
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int color[], int col) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (dfs(graph, it, color, !col) == false) {
                    return false;
                }
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        int color[v];

        for (int i = 0; i < v; i++) {
            color[i] = -1;
        }

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (dfs(graph, i, color, 0) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
