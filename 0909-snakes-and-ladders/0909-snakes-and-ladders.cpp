class Solution {
public:
    pair<int,int> cor(int a, int n) {
        a--;
        int i=a/n;
        int x=n-i-1;
        int y=a%n;
        if ((n-x) % 2 == 0) {
            y = n - y - 1;
        }

        return {x, y};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int,int>>visited(n*n+1,{-1,-1});
        queue<int>q;
        visited[1].first=1;
        visited[1].second=1;
        q.push(1);
        int ans=0;
        for(int i=0;i<=n*n;i++){
            auto [x,y]=cor(i,n);
        }
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                int pos=q.front();
                q.pop();
                for(int i=1;i<7;i++){
                    int next=pos+i;
                    if(visited[next].first !=-1)continue;
                    if(next==n*n)return ans;
                    auto [x,y]=cor(next,n);
                    if(board[x][y]!=-1 && visited[board[x][y]].second==-1){
                        if(board[x][y]==n*n)return ans;
                        visited[board[x][y]].second=1;
                        q.push(board[x][y]);
                    }
                    if(board[x][y]==-1){
                        q.push(next);
                    }
                    visited[next].first=1;

                }
            }
        }
        return -1;
    }
};