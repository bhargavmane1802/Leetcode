class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int n=s1.size();
        int m=s2.size();
        int l=0;
        int r=0;
        vector<vector<int>>ans;
        while(l<n && r<m){
            if(s1[l][0]==s2[r][0]){
                ans.push_back({s1[l][0],s1[l][1]+s2[r][1]});
                l++;
                r++;
            }
            else if(s1[l][0]<s2[r][0]){
                ans.push_back({s1[l][0],s1[l][1]+s2[r][1]});
                l++;
            }
            else {
                ans.push_back({s2[r][0],s1[l][1]+s2[r][1]});
                r++;
            }
        }
        while(l<n){
            ans.push_back({s1[l][0],s1[l][1]});
            l++;
        }
        while(r<m){
            ans.push_back({s2[r][0],s2[r][1]});
            r++;
        }
        return ans;
        
    }
};