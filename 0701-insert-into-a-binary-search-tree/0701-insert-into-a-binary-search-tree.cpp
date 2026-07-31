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
    TreeNode* insertIntoBST(TreeNode* root, int t) {
        if(!root){
            TreeNode* temp=new TreeNode(t);
            return temp;
        }
        if(root->val<t){
            if(root->right)insertIntoBST(root->right,t);
            else{
                TreeNode* temp=new TreeNode(t);
                root->right=temp;
            }
        }
        else {
            if(root->left)insertIntoBST(root->left,t);
            else{
                TreeNode* temp=new TreeNode(t);
                root->left=temp;
            }
        }
        return root;
    }
};