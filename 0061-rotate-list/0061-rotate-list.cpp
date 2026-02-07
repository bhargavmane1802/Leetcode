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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int n=0;
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==n)return head;
        k=n-k;
        ListNode*prev=NULL;
        ListNode*curr=head;
        temp=head;
        while(k>0){
            k--;
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode*store=prev;
        prev=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head->next=prev;
        curr=store;
        prev=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};