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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode*a=l1;
        ListNode*b=l2;
        while(l1 && l2){
            int sum=l1->val+l2->val+c;
            if(sum>=10){
                c=1;
                l1->val=sum-10;
                l2->val=sum-10;
            }
            else{
                c=0;
                l1->val=sum;
                l2->val=sum;
            }
            l1=l1->next;
            l2=l2->next;
        }
        ListNode* ans;
        ListNode*head;
        if(l1){
            head=a;
            ans=l1;
        }
        else{
            head=b;
            ans=l2;
        }
        while(ans && c==1){
            int sum=ans->val+c;
            if(sum>=10){
                c=1;
                ans->val=sum-10;
            }
            else{
                c=0;
                ans->val=sum;
            }
            ans=ans->next;
        }
        ans=head;
        if(c==1){
            while(ans->next){
                ans=ans->next;
            }
            ListNode* x=new ListNode(1);
            ans->next=x;
        }
        return head;
    }
};