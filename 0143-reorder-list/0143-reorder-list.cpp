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
    void reorderList(ListNode* head) {
        int s=0;
        ListNode* temp=head;
        while(temp){
            s++;
            temp=temp->next;
        }
        int c=s-(s/2);
        temp=head;
        while(c>0){
            c--;
            temp=temp->next;
        }
        ListNode*prev=NULL;
        while(temp){
            swap(temp->next,prev);
            swap(temp,prev);
        }
        temp=head;
        ListNode*store;
        while(s>0){
            s--;
            swap(temp->next,prev);
            temp=temp->next;
        }
        if(temp)temp->next=NULL;
    }
};