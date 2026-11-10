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
ListNode* reverseList(ListNode * root){
    ListNode* prev=NULL,*curr=root;
    while(curr){
        swap(prev,curr->next);
        swap(prev,curr);
    }
    return prev;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return l1;
        if(!l1)return l2;
        if(!l2)return l1;
        // l1=reverseList(l1);
        // l2=reverseList(l2);
        ListNode * curr1=l1;
        ListNode *curr2=l2;
        ListNode * prev;
        ListNode* head=curr1;;
        int carry=0;
        while(curr1 && curr2){
            prev=curr1;
            int sum=curr1->val +curr2->val+carry;
            int unit=sum%10,tens=sum/10;
            carry=tens;
            curr1->val=unit;
            curr2->val=unit;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(curr2){
            curr1=curr2;
            head=l2;
        }
        while(curr1){
                prev=curr1;
                int sum=curr1->val+carry;
                int unit=sum%10,tens=sum/10;
                carry=tens;
                curr1->val=unit;
                curr1=curr1->next;
        } 
        if(carry!=0){
            ListNode * newNode=new ListNode(carry);
            prev->next=newNode;
        }
        return head;
    }
};