class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>mp(n);
        queue<int>q;
        vector<int>visited(n);
        for(int i=0;i<n;i++){
            int r=i+arr[i];
            if(r<n)mp[i].push_back(r);
            r=i-arr[i];
            if(r>=0)mp[i].push_back(r);
        }
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(arr[top]==0)return true;
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