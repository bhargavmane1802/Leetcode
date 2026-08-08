class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>temp(26);
            int mx=INT_MIN;
            for(int j=i;j<n;j++){
                temp[s[j]-'a']++;int mn=INT_MAX;
                for(int j:temp){
                    if(j==0)continue;
                    mn=min(mn,j);
                    mx=max(mx,j);
                }
                sum+=(mx-mn);
            }
        }
        return sum;
    }
};