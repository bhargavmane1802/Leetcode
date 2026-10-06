class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]={i,i};
            }
            else mp[s[i]].second=i;
        }
        vector<vector<int>>merge;
        for(auto x:mp){
            merge.push_back({x.second.first,x.second.second});
        }
        sort(merge.begin(),merge.end());
        vector<vector<int>>merged;
        merged.push_back(merge[0]);
        int x=0;
        for(int i=1;i<merge.size();i++){
            if(merged[x][1]>merge[i][0]){
                merged[x][1]=max(merge[i][1],merged[x][1]);
            }
            else {
                merged.push_back(merge[i]);
                x++;
            }
        }
        // for(auto a:merged)cout<<a[0]<<"-"<<a[1]<<" ";
        vector<int>ans;
        for(auto a:merged)ans.push_back(a[1]-a[0]+1);
        return ans;

    }
};