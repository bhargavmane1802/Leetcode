class Solution {
public:
    void cs(int ind,int s,int t,vector<int >& can,vector<int>temp,vector<vector<int>>&ans){
        if (s==t){
            ans.push_back(temp);
            return;
        }
        if(s>t ||ind>=can.size()){
            return;
        }
        int i=ind;
        unordered_set<int>x;
        for(i;i<can.size();i++){
            if(x.find(can[i])==x.end()){
                x.insert(can[i]);
                temp.push_back(can[i]);
                cs(i+1,s+can[i],t,can,temp,ans);
                temp.pop_back();
            }
            if(s+can[i]>t){
                return;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        cs(0,0,target,candidates,{},ans);
        return ans;
    }
};