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
int ans=0;
    bool solve(TreeNode*root,int &mx,int &mn,int&sum){
        if(!root){
            mx=INT_MIN;
            mn=INT_MAX;
            sum=0;
            return true;
        }
        int s1=0;
        bool one=true;
        if(!(solve(root->left,mx,mn,s1) && root->val>mx)){
            one=false;
        }
        int s=0;
        int mnn=mn;
        bool two=true;
        if(!(solve(root->right,mx,mn,s) && root->val<mn)){
            two=false;
        }
        if(!one || !two)return false;
        sum+=root->val+s+s1;
        ans=max(ans,sum);
        mx=max(mx,root->val);
        mn=min(mnn,root->val);
        return true;
    }

    int maxSumBST(TreeNode* root) {
        int sum=0;
        int mx=INT_MAX;
        int mn=INT_MIN;
        solve(root,mx,mn,sum);
        return ans;
    }
};