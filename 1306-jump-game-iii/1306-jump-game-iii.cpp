class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>mp(n);
        queue<int>q;
        vector<int>visited(n);
        for(int i=0;i<n;i++){
            if(0==arr[i]){q.push(i);visited[i]=1;}
            
            int r=i+arr[i];
            if(r<n)mp[r].push_back(i);
            r=i-arr[i];
            if(r>=0)mp[r].push_back(i);
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(top==start)return true;
            for(int i :mp[top]){
                if(visited[i]==0){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        return false;
    }
};