class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // x = vertical column
        // y = level / row
        // multiset = keeps values sorted when
        // multiple nodes have same x and y
        map<int, map<int, multiset<int>>> nodes;

        // {node, {x, y}}
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {

            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;

            int x = p.second.first;
            int y = p.second.second;

            // Store node according to its column and level
            nodes[x][y].insert(node->val);

            // Left child
            // x decreases by 1
            // y increases by 1
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }

            // Right child
            // x increases by 1
            // y increases by 1
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        // Traverse columns from left to right
        for (auto &p : nodes) {

            vector<int> col;

            // Traverse levels from top to bottom
            for (auto &q : p.second) {

                // Values are already sorted
                for (auto &value : q.second) {
                    col.push_back(value);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};