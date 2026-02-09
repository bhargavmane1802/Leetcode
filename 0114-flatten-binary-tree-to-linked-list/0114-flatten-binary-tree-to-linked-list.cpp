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
    TreeNode* curr=new TreeNode();
    void solve(TreeNode* root){
        if(!root)return ;
        TreeNode* l=root->left;
        TreeNode*r=root->right;
        curr->left=NULL;
        curr->right=root;
        curr=curr->right;
        solve(l);
        solve(r);

    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};