class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>temp(5);
        for(char c:text){
            if(c=='b')temp[0]++;
            else if( c=='a')temp[1]++;
            else if(c=='l')temp[2]++;
            else if(c=='o')temp[3]++;
            else if(c=='n')temp[4]++;
        }
        temp[2]=temp[2]/2;
        temp[3]=temp[3]/2;
        int ans=INT_MAX;
        for(int i:temp){
            ans=min(ans,i);
        }
        if(ans==INT_MAX)return 0;
        else return ans;
        
    }
};