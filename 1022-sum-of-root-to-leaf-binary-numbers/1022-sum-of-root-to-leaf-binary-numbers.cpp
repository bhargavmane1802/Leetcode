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
    void dfs(TreeNode*root,int csum,int & sum){
        if(!root){

            return;
        }
        csum=(csum*2)+root->val;
        dfs(root->left,csum,sum);
        dfs(root->right,csum,sum);
        if(!root->left && !root->right)sum+=csum;
        return;
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        dfs(root,0,sum);
        return sum;
        
    }
};