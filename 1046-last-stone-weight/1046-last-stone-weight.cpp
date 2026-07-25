class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i:stones){
            q.push(i);;
        }
        
        while(!q.empty()){
            if(q.size()==1)return q.top();
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            if(x==y)continue;
            q.push(x-y);

        }
        return 0;
    }
};