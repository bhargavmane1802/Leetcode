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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode* front=head;
        while(n>0){
            front=front->next;
            n--;
        }
        if(!front)return head->next;
        ListNode* curr=head;
        while(front->next){
            front=front->next;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;

    }
};