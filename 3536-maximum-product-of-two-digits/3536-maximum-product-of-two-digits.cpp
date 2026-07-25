class Solution {
public:
    int maxProduct(int n) {
       priority_queue<int,vector<int>,greater<int>>q;
       int x=n;
       while(x>0){
        int a=x%10;
        x/=10;
        if(q.size()<2){
            q.push(a);
        }
        else if(q.size()==2 && q.top()<=a){
            q.pop();
            q.push(a);
            
        }
       }
       int ans=q.top();
       q.pop();
       return ans*q.top();
        
    }
};