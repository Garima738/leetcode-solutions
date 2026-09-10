/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans = 0;
    pair<int,int> sum(TreeNode* root){
        if(root==NULL) return {0,0};

        pair<int,int> leftsubtree = sum(root->left);
        pair<int,int> rightsubtree = sum(root->right);

        int currentsum = leftsubtree.first+rightsubtree.first+root->val;
        int count = leftsubtree.second+rightsubtree.second+1;

        int average = currentsum/count;

        if(average == root->val){
            ans++;
        }
        return{currentsum,count};



    }
    int averageOfSubtree(TreeNode* root) {
        //int ans = 0;
        sum(root);
        return ans;

        
    }
};