/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode* t1 =A;
        ListNode* t2=B;
        while(t1 != t2){
            if(!t1){
                t1=B;
            }
            else{
                t1=t1->next;
            }
            if(t2)t2=t2->next;
            else t2=A;
        }
        return t1;
    }
};