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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        ans=max(ans,max(max(root->val,root->val+max(l,r)),root->val+l+r));
        return max(root->val,root->val+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};