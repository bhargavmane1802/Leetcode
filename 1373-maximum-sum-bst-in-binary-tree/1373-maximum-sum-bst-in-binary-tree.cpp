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
    vector<int> solve(TreeNode*root,int &ans){
        int sum=root->val,m=root->val,mx=root->val;
        int check=1;
        if(root->left){
            auto x=solve(root->left,ans);
            sum+=x[0];
            m=min(m,(min(x[2],x[1])));
            mx=max(mx,max(x[1],x[2]));
            if(x[3]==0 || root->val <=x[1] || root->val<=x[2])check=0;
        }
        
        if(root->right){
            auto y=solve(root->right,ans);
            sum+=y[0];
            m=min(m,min(y[1],y[2]));
            mx=max(mx,max(y[1],y[2]));
            if(y[3]==0 || root->val>=y[1] || root->val>=y[2])check=0;
        }
        if(check==1)ans=max(ans,sum);
        return {sum,m,mx,check};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        if(!root)return ans;
        solve(root,ans);
        return ans;
    }
};