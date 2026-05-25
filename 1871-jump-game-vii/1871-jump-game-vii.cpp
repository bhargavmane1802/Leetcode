class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        if(n==1)return true;
        if(s[n-1]=='1')return false;
        vector<int>visited(n);
        q.push(0);
        int m=0;
        visited[0]=1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int l=max(m,(t+minJump));
            while(l<n && l<=maxJump+t){
                if(s[l]=='0' && visited[l]==0){
                    if((l)==n-1)return true;
                    q.push(l);
                    visited[l]=1;
                }
                m=max(l,m);
                l++;
            }
        }
        return false;
    }
};