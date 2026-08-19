class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int,vector<int>>temp;
        for(auto &x:r){
            if(temp[x[0]].size()!=0)continue;
            temp[x[0]]={1,1,1};
        }
        for(auto &x:r){
            int a=x[1];
            if(a>=2 && a<=5)temp[x[0]][0]=0;
            if(a>=4 && a<=7)temp[x[0]][1]=0;
            if(a>=6 && a<=9)temp[x[0]][2]=0;
        }
        int ans=(n-(temp.size()))*2;
        for(auto & x:temp){
            auto & t=x.second;
            if(t[0] && t[2])
                ans += 2;
            else if(t[0] || t[1] || t[2])
                ans += 1;

        }
        return ans;
        
    }
};