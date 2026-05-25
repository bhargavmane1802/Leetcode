class Solution {
public:
    bool isBipartite(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>visited(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=1;
                q.push(i);
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    int x;
                    int y=visited[t];
                    if(y==1)x=0;
                    else x=1;
                    for(int i:nums[t]){
                        if(visited[i]==-1){
                            q.push(i);
                            visited[i]=x;
                        }
                        else if(visited[i]==y)return false;
                    }
                }
            }
        }
        return true;
        
    }
};