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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        ListNode*s;
        int i=0;
        temp=head;
        int check=0;
        ListNode* store=head;

        while((n-i)>=k){
            ListNode* prev=NULL;
            s=temp;
            int x=k;
            while(x>0){
                i++;
                x--;
                swap(prev,s->next);
                swap(prev,s);
            }
            if(check==0){
                head=prev;
                check=1;
            }
            else {
                store->next=prev;
            }
            store=temp;
            temp=s;
        }
        store->next=temp;
        return head;
    }
};