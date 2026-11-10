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
    ListNode * reverseList(ListNode*head){
        ListNode* prev=NULL ,*curr=head;
        while(curr){
            swap(curr->next,prev);
            swap(curr,prev);
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode *fast=head;
        if(!head || !head->next)return ;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        fast=reverseList(fast);
        while(fast){
            ListNode* temp=slow->next;
            slow->next=fast;
            fast=fast->next;
            slow->next->next=temp;
            slow=slow->next->next;
        }
        return ;
    }
};