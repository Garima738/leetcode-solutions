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
     void solve(TreeNode* root,vector<string>&path,vector<string>&ans){
        if(root==NULL) return;
           path.push_back(to_string(root->val));
        if(root->left==NULL && root->right==NULL){
            string s = path[0];
            for (int i = 1; i < path.size(); i++) {
                s += "->" + path[i];
            }
            ans.push_back(s);
        }
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        path.pop_back();
     }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>path;
        vector<string>ans;
        solve(root,path,ans);
        return ans;
        
    }
};