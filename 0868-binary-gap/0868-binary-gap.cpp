class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int prev=0;
        int i=0;
        while(n>0){
            i++;
            if(n%2==1){
                if(prev==0)prev=i;
                else{
                    ans=max(ans,(i-prev));
                    prev=i;
                }
            }
            n/=2;
        }
        return ans;
    }
};