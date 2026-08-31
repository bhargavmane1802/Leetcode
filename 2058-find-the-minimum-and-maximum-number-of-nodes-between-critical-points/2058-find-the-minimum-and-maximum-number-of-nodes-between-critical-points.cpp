/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)return {-1,-1};
        vector<int>temp;
        int x=0;
        ListNode* curr=head->next;
        int prev=head->val;
        while(curr->next){
            if(prev<curr->val && curr->val>curr->next->val)temp.push_back(x);
            if(prev>curr->val && curr->val<curr->next->val)temp.push_back(x);
            prev=curr->val;
            x++;
            curr=curr->next;
        }
        vector<int>ans(2);
        ans[0]=INT_MAX;
        ans[1]=INT_MIN;
        if(temp.size()<2)return {-1,-1};
        if(temp.size()==1)return {0,0};
        for(int i=1;i<temp.size();i++){
            ans[0]=min(ans[0],temp[i]-temp[i-1]);
        }
        ans[1]=temp.back()-temp[0];
        return ans;
        
        
    }
};