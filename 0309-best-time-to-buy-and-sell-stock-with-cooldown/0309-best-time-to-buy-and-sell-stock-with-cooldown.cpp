class Solution {
public:
    int solve(vector<int>&p,int idx,int prev,vector<vector<int>>&state){
        if(idx>=p.size()){
            return 0;
        }
        if(prev==-1){
            if(state[idx][0]!=-1)return state[idx][0];
            int a=solve(p,idx+1,prev,state);
            int b=solve(p,idx+1,p[idx],state);
            return state[idx][0]=max(a,b);
        }
        else {
            // if(state[idx][1]!=-1)return state[idx][1];
            int a=p[idx]-prev+solve(p,idx+2,-1,state);
            int b=solve(p,idx+1,prev,state);
           return state[idx][1]=max(a,b);
        }
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>state(n,vector<int>({-1,-1}));
        return solve(p,0,-1,state);
    }
};