// class Solution {
// public:
//     void solve(string & s, string &t,int idx,int &ans,int ti){
//         if(ti>=t.size()){
//             ans++;
//             return ;
//         }
//        if(idx>=s.size())return ;
//        if(s.size()-idx<t.size()-ti)return;
//         solve(s,t,idx+1,ans,ti);
//         if(s[idx]==t[ti]){
//             solve(s,t,idx+1,ans,ti+1);
//         }

//     }
//     int numDistinct(string s, string t) {
//         int ans=0;
//         solve(s,t,0,ans,0);
//         return ans;
//     }
// };

class Solution {
public:
    int solve(string &s, string &t, int idx, int ti, vector<vector<int>>& dp) {
        if (ti == t.size())
            return 1;

        if (idx == s.size())
            return 0;

        if (s.size() - idx < t.size() - ti)
            return 0;

        if (dp[idx][ti] != -1)
            return dp[idx][ti];

        int ans = solve(s, t, idx + 1, ti, dp);

        if (s[idx] == t[ti]) {
            ans += solve(s, t, idx + 1, ti + 1, dp);
        }

        return dp[idx][ti] = ans;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

        return solve(s, t, 0, 0, dp);
    }
};