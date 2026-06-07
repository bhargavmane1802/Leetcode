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
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        int n=nums.size();
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>child;
        for(int i=0;i<n;i++){
            int p=nums[i][0];
            int c=nums[i][1];
            int left=nums[i][2];
            if(mp[p]==NULL){
                TreeNode * node=new TreeNode(p);
                mp[p]=node;
            }
            if(mp[c]==NULL){
                    TreeNode * node=new TreeNode(c);
                    mp[c]=node;
                }
            if(left==1){
                mp[p]->left=mp[c];
            }
            else{
                mp[p]->right=mp[c];
            }
            child.insert(c);
        }
        for(auto i : mp){
            if(child.find(i.first)==child.end())return i.second;
        }
        return NULL;
    }
};