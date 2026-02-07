class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        vector<int>visited(a+1,INT_MAX);
        visited[0]=1;
        for(int i=0;i<a;i++){
            if(visited[i]==INT_MAX)continue;
            for(int c:coins){
                if(i+c <=a){
                    visited[i+c]=min(visited[i+c],visited[i]+1);
                }
            }
        }
        if(visited[a]==INT_MAX)return-1;
        return visited[a]-1; 
    }
};