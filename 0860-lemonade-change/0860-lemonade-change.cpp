class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c=0;
        int t=0;
        int w=0;
        for(int i:bills){
            if(i==5)c++;
            else if(i==10){
                if(c==0)return false;
                c--;
                t++;
            }
            else if(i==20){
                if(t>=1 && c>=1){
                    t--;
                    c--;
                    w++;
                }
                else if(c>=3){
                    c-=3;
                    w++;
               }
               else return false;
            }
            else return false;
            
        }
        return true;
    }
};