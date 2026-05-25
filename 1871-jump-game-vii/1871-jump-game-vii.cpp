class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        if(n==1)return true;
        if(s[n-1]=='1')return false;
        q.push(0);
        int m=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int l=max(m,(t+minJump));
            while(l<n && l<=maxJump+t){
                if(s[l]=='0'){
                    if((l)==n-1)return true;
                    q.push(l);
                }
                l++;
            }
            m=max(m,maxJump+t+1);
        }
        return false;
    }
};