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
    int h(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int l=h(root->left);
        if(l==-1)return-1;
        int r=h(root->right);
        if(r==-1)return-1;
        if(l-r>1||r-l>1){
            return -1;
        }
        return(max(l,r))+1;
    }
    bool isBalanced(TreeNode* root) {
        return h(root)!=-1;
        
    }
};