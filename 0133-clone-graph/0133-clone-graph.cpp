/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<Node*,Node*>check;
        Node* head=new Node(node->val);
        queue<pair<Node*,Node*>>q;
        q.push({node,head});
        check[node]=head;
        while(!q.empty()){
            Node * a=q.front().first;
            Node * b=q.front().second;
            q.pop();
            for( Node* y:a->neighbors){
                if(check.find(y)!=check.end()){
                    b->neighbors.push_back(check[y]);
                    continue;
                }
                Node* newNode =new Node(y->val);
                check[y]=newNode;
                b->neighbors.push_back(newNode);
                q.push({y,newNode});
            }
        }
        return head;

    }
};