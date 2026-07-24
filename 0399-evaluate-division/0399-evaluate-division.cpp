class Solution {
public:
    void bfs(unordered_map<string,vector<pair<double,string>>>& mp,string s,string e,vector<double>&ans){
        if(e==s){
            if(mp[s].size()>0)ans.push_back(1.0);
            else ans.push_back(-1.0);
            return;
        }
        unordered_map<string,int>visited;
        queue<pair<string,double>>q;
        visited[s]=1;
        q.push({s,1.0});
        while(!q.empty()){
            string i=q.front().first;
            double j=q.front().second;
            q.pop();
            for(auto x:mp[i]){
                double t1=x.first*j;
                string t2=x.second;
                if(t2==e){
                    ans.push_back(t1);
                    return ;
                }
                if(visited[t2]==1)continue;
                visited[t2]=1;
                q.push({t2,t1});
            }
        }
        ans.push_back(-1.0);
        return ;
    }

    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& queries) {
        vector<double>ans;
        unordered_map<string,vector<pair<double,string>>>mp;
        int i=0;
        for(auto x:e){
            mp[x[0]].push_back({v[i],x[1]});
            mp[x[1]].push_back({(double)(1.0/v[i]),x[0]});
            i++;
        }
        for(auto x:queries){
            string start=x[0];
            string end=x[1];
            bfs(mp,start,end,ans);
        }
        return ans;
    }
};