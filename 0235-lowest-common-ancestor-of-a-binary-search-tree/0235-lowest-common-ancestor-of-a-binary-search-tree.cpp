/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(!root)return;
        if(root->val>=p->val && root->val>=q->val){
            if(root->val==p->val ||root->val==q->val){
                ans=root;
                return ;
            }
            else solve(root->left,p,q,ans);
        }
        else if(root->val<=p->val && root->val<=q->val){
            if(root->val==p->val ||root->val==q->val){
                ans=root;
                return ;
            }
            else solve(root->right,p,q,ans);
        }
        else {
            ans=root;
            return ;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        solve(root,p,q,ans);
        return ans;
    }
};