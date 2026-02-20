class Solution {
public:
    void solve(TreeNode* root, long long targetSum, int& count) {
        if (root == NULL) return;

        if (root->val == targetSum)
            count++;

        solve(root->left, targetSum - root->val, count);
        solve(root->right, targetSum - root->val, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        int count = 0;

        solve(root, targetSum, count);

      
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};