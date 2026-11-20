class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),[](auto &x,auto &y){
            if(x[1]==y[1])return x[0]>y[0];
            return x[1]<y[1];
        });
        vector<vector<int>>temp;
        temp.push_back(inter[0]);
        for(int i=1;i<int(inter.size());i++){
            if(inter[i][0]<temp.back()[1])continue;
            temp.push_back(inter[i]);
        }
        return (int(inter.size())-int(temp.size()));
    }
};