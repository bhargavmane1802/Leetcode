class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        vector<int>visited(n);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1 && arr[i]==arr[i-1] && arr[i]==arr[i+1])continue;
            mp[arr[i]].push_back(i);
        }
        int ans=-1;
        int top;
        int s;
        while(!q.empty()){
            s=q.size();
            ans++;
            for(int j=0;j<s;j++){
                top=q.front();
                q.pop();
                if(top==n-1)return ans;
                if(0!=top && visited[top-1]==0){
                    q.push(top-1);
                    visited[top-1]=1;
                }
                if(top!=n-1 && visited[top+1]==0){
                    q.push(top+1);
                    visited[top+1]=1;
                }
                for(int k:mp[arr[top]]){
                    if(visited[k]==0){
                        q.push(k);
                        visited[k]=1;
                    }
                }
                mp.erase(arr[top]);
            }
        }
        return ans;
        
    }
};