/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* start = new Node(head->val);
        Node *root = head, *temp = head, *temp2 = start;
        unordered_map<Node*,int> mp;
        vector<Node*>v;
        int c=0;
        while (temp->next) {
            Node* new_Node = new Node(0);
            temp2->val = temp->val;
            temp2->next=new_Node;
            v.push_back(temp2);
            mp[temp]=c;
            c++;
            temp=temp->next;
            temp2=new_Node;
        }
        temp2->val = temp->val;
        v.push_back(temp2);
        v.push_back(NULL);
        mp[temp]=c;
        mp[NULL]=c+1;
        temp=head;
        temp2=start;
        while(temp){
            temp2->random=v[mp[temp->random]];
            temp=temp->next;
            temp2=temp2->next;
        }
        return start;
    }
};