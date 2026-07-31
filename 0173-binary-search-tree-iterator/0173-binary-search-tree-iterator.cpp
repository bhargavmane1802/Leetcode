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
class BSTIterator {
public:
    vector<int>temp;
    int x;
    int i=0;
    BSTIterator(TreeNode* root) {
        solve(root);
        x=temp.size();
    }
    void solve(TreeNode*root){
        if(!root)return ;
        solve(root->left);
        temp.push_back(root->val);
        solve(root->right);
    }
    
    int next() {
        i++;
        return temp[i-1];
    }
    
    bool hasNext() {
        if(i>=x)return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */