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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        int n=list.size();
        for(int i=0;i<n;i++){
            auto x =list[i];
            if(x){
                q.push({x->val,x});
            }
        }
        if(q.empty())return NULL;
        ListNode* start=q.top().second;
        if(q.size()==1)return q.top().second;
        ListNode*temp=start;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            if(x.second->next){
                q.push({x.second->next->val, x.second->next});
            }
            temp->next=x.second;
            temp=temp->next;
        }
        return start;
        
    }
};