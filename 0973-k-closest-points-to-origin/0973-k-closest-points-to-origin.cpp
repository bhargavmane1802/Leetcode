class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>q;
        for(auto x:points){
            int a=x[1]*x[1];
            int b=x[0]*x[0];
            int c=a+b;
            if(q.size()<k){
                q.push({c,{x[0],x[1]}});
            }
            else if(q.top().first>=c){
                q.pop();
                q.push({c,{x[0],x[1]}});

            }
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return ans;
    }
};