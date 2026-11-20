class Solution {
public:
    bool solve(vector<vector<char>>& board, string & word,vector<int>&row,vector<int>&col,int a,int b,vector<vector<int>>&visited,int idx,int n,int m){
        if(idx>=int(word.size()))return true;
        cout<<board[a][b]<<" ";
        for(int i=0;i<4;i++){
            int x=a+row[i];
            int y=b+col[i];
            if(x>=0 && y>=0 && x<n && y<m && visited[x][y]==0 && board[x][y]==word[idx]){
                visited[x][y]=1;
                if(idx+1>=int(word.size()))return true;
                if(solve(board,word,row,col,x,y,visited,idx+1,n,m))return true;
                visited[x][y]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;

        int n = board.size(), m = board[0].size();

        if (word.size() > n * m) return false;

        vector<int> freq(128, 0);

        for (auto& r : board) {
            for (char c : r) {
                freq[c]++;
            }
        }

        vector<int> need(128, 0);

        for (char c : word) {
            need[c]++;
            if (need[c] > freq[c]) return false;
        }

        if (freq[word.back()] < freq[word[0]]) {
            reverse(word.begin(), word.end());
        }
        vector<int >row{1,-1,0,0};
        vector<int>col{0,0,1,-1};
        vector<vector<int>>visited(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    if(solve(board,word,row,col,i,j,visited,1,n,m))return true;
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};