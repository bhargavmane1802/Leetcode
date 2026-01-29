class Solution {
public:
    int solve(int n){
        int ans=0;
        while(n>0){
            if(n%2==1)ans++;
            n/=2;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int>temp;
        for(int i=0;i<=n;i++){
            temp.push_back(solve(i));
        }
        return temp;
    }
};