class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        stack<int>s;
        for(int i=0;i<h.size();i++){
            ans=max(ans,h[i]);
           if(s.empty())s.push(i);
           else{
                int curr=h[i];
                while(!s.empty() && h[s.top()]>=h[i]){
                    curr+=h[i];
                    s.pop();
                }
                ans=max(ans,curr);
                s.push(i);
           }
        }
        stack<int>q;
        int m=h[0];
        for(int i=h.size()-1;i>=0;i--){
            m=min(m,h[i]);
            ans=max(ans,h[i]);
           if(q.empty())q.push(i);
           else{
            int curr=h[i];
            while(!q.empty() && h[q.top()]>=h[i]){
                curr+=h[i];
                q.pop();
            }
            ans=max(ans,curr);
            q.push(i);
           }
        }
        int n=h.size();
        return max((m*n),ans);
    }
};