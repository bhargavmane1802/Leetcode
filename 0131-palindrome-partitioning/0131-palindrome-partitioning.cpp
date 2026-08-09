class Solution {
public:
    void solve(int idx,unordered_map<int,vector<string>>&temp,string & s,vector<vector<string>>&ans,vector<string >store){
        if(idx==s.size()){
            ans.push_back(store);
            return ;
        }
        if(idx>s.size())return;
        for(auto x:temp[idx]){
            store.push_back(x);
            solve(idx+x.size(),temp,s,ans,store);
            store.pop_back();
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        unordered_map<int,vector<string>>temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                temp[l].push_back(s.substr(l,r-l+1));
                l--;
                r++;

            }
            if(i<n-1 && s[i]==s[i+1]){
                l=i;
                r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    temp[l].push_back(s.substr(l,r-l+1));
                    l--;
                    r++;
                }
            }
        }
        vector<vector<string>>ans;
        solve(0,temp,s,ans,{});
        return ans;
    }
};