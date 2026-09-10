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
    pair<int,int> solve(TreeNode *root,int & ans){
        if(!root)return {0,0};
        auto left=solve(root->left,ans);
        auto right =solve(root->right,ans);
        int x=(root->val+left.first+right.first)/(1+left.second+right.second);
        if(x==root->val)ans++;
        return {(root->val+left.first+right.first),(1+left.second+right.second)};

    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;

    }
};