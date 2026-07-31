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
int i=1;
    void solve(TreeNode* root,vector<int>&nums,int m,int mx){
        if(i>=nums.size())return ;
        if(nums[i]<root->val && nums[i]<mx && nums[i]>m){
            TreeNode*t=new TreeNode(nums[i]);
            i++;
            root->left=t;
            solve(root->left,nums,m,root->val);
        }
        if(i>=nums.size())return ;
        if(nums[i]>root->val  && nums[i]<mx && nums[i]>m){
            TreeNode*t=new TreeNode(nums[i]);
            i++;
            root->right=t;
            solve(root->right,nums,root->val,mx);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        TreeNode*root=new TreeNode(nums[0]);
        solve(root,nums,INT_MIN,INT_MAX);
        return root;
    }
};