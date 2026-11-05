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
    void solve(TreeNode* root ,int & tsum,int &csum,vector<vector<int>>&ans,vector<int>&path){
        if(!root){
            return;
        }
        csum+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(tsum==csum){
                ans.push_back(path);
            }
            csum-=root->val;
            path.pop_back();
            return ;
        }
        solve(root->left,tsum,csum,ans,path);
        solve(root->right,tsum,csum,ans,path);
        csum-=root->val;
        path.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int tsum) {
        vector<vector<int>>ans;
        vector<int>path;
        int csum=0;
        solve(root,tsum,csum,ans,path);
        return ans;
    }
};