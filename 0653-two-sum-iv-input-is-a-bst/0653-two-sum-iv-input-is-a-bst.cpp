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
    bool solve(TreeNode*root,int k,unordered_set<int>&visited){
        if(!root)return false;
        int val=root->val;
        if(visited.find(k-val)!=visited.end())return true;
        visited.insert(val);
        if(solve(root->left,k,visited))return true;
        if(solve(root->right,k,visited))return true;
        return false;

    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>visited;
        return solve(root,k,visited);
    }
};