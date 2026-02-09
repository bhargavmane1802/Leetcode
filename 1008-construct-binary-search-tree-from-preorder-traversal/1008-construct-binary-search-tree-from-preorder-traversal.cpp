class Solution {
public:
    int i = 0;
    TreeNode* build(vector<int>& nums, int bound) {
        if (i == nums.size() || nums[i] > bound) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[i]);
        i++;
        root->left = build(nums, root->val);
        root->right = build(nums, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        return build(nums, INT_MAX);
    }
};