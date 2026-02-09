/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>s;
        s.push(root);
        Node* prev=NULL;
        while(!s.empty()){
            int n=s.size();
            prev=NULL;
            for(int i=0;i<n;i++){
                if(s.front()->right)s.push(s.front()->right);
                if(s.front()->left)s.push(s.front()->left);
                s.front()->next=prev;
                prev=s.front();
                s.pop();
            }
        }
        return root;
    }
};