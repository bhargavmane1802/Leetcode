class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }
        else{
            int s=q.size();
            q.push(x);
            for(int i=0;i<s;i++){
                int t=q.front();
                q.pop();
                q.push(t);
            }
        }
    }
    
    int pop() {
        int t=q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */