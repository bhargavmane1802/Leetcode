class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        vector<int>temp(n);
        stack<int>s;
        for(int i=0;i<n;i++){
           while(!s.empty() && h[s.top()]>=h[i]){
            s.pop();
           }
           if(s.empty()){
            temp[i]=-1;
           }
           else {
            temp[i]=s.top();
           }
           s.push(i);
        }
        stack<int>t;
        for(int i=n-1;i>=0;i--){
            while(!t.empty() && h[t.top()]>=h[i]){
            t.pop();
           }
           if(t.empty()){
            ans=max(ans,h[i]*(n-temp[i]-1));
           }
           else {
            ans=max(ans,h[i]*(t.top()-temp[i]-1));
           }
           t.push(i);
        }
        return ans;
    }
};