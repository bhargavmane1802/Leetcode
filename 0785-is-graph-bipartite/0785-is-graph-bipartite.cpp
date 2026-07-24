class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                q.push(i);
                visited[i]=0;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    int v;
                    if(visited[x]==0)v=1;
                    else v=0;
                    for(int j:graph[x]){
                        if(visited[j]==-1){
                            visited[j]=v;
                            q.push(j);
                        }
                        else if(visited[x]==visited[j])return false;
                    }
                }
            }
        }
        return true;
    }
};