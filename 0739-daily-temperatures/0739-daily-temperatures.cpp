class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        int n=t.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && t[s.top()]<=t[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }
            else {
                ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};