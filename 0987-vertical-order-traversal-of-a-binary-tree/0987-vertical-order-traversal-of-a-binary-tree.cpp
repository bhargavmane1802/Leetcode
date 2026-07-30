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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int y=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto a=q.front();
                q.pop();
                TreeNode*t=a.first;
                int x=a.second;
                mp[x].push_back({y,t->val});
                if(t->left){
                    q.push({t->left,x-1});
                }
                if(t->right)q.push({t->right,x+1});
            }
            y++;
        }
        vector<vector<int>>ans;
        for(auto a:mp){
            vector<int>temp;
            sort(a.second.begin(),a.second.end());
            for(auto i:a.second){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};