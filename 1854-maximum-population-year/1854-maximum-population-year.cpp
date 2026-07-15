class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>years(101);
        for(auto l:logs){
            years[l[0]-1950]++;
            years[l[1]-1950]--;
        }
        int ans=0;
        int pop=0;
        int m=0;
        for(int i=0;i<101;i++){
            pop+=years[i];
            if(m<pop){
                m=pop;
                ans=i;
            }
        }
        return 1950+ans;
    }
};