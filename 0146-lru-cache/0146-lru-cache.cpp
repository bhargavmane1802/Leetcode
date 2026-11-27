class Node{
    public:
    int val;
    Node*next;
    Node*prev;
    Node(int v){
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int lim=0;
    int cap;
    unordered_map<Node*,int>check;
    unordered_map<int,Node*>mp;
    Node*head=NULL;
    Node*tail;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node*curr=mp[key];
        int r=curr->val;
        if((curr==head && !curr->next)|| curr==tail) return r;
        if(curr==head){
            head=head->next;
            head->prev=NULL;
            tail->next=curr;
            curr->prev=tail;
            curr->next=NULL;
            tail=curr;
        }
        else{
            (curr->prev)->next=curr->next;
            curr->next->prev=curr->prev;
            curr->prev=tail;
            tail->next=curr;
            curr->next=NULL;
            tail=curr;
        }
        return r;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
      if(mp.find(key)==mp.end()){
        Node*node=new Node(value);
        mp[key]=node;
        check[node]=key;
        if(lim>=cap){
            if(cap==1){
            head->val=value;
            mp.erase(check[head]);
            mp[key]=head;
            check[head]=key;
            return;
        }
            mp.erase(check[head]);
            check.erase(head);
            head=head->next;
            head->prev=NULL;
            tail->next=node;
            node->prev=tail;
            tail=node;

        }
        else{
            lim++;
            if(head==NULL){
                tail=node;
                head=node;
            }else{
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
        }
      }  
      else{
        Node*curr=mp[key];
        curr->val=value;
        if((curr==head && !curr->next)|| curr==tail) return;
        if(curr==head){
            head=head->next;
            head->prev=NULL;
            tail->next=curr;
            curr->prev=tail;
            curr->next=NULL;
            tail=curr;
        }
        else{
            (curr->prev)->next=curr->next;
            curr->next->prev=curr->prev;
            curr->prev=tail;
            tail->next=curr;
            curr->next=NULL;
            tail=curr;
        }
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */