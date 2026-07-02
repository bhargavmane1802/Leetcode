class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>temp(amount+1,INT_MAX-1);
        temp[0]=0;
        for(int j=0;j<coins.size();j++){
            for(int i=coins[j];i<=amount;i++){
                temp[i]=min(temp[i],temp[i-coins[j]]+1);
            }
        }
        if(temp[amount]==INT_MAX-1)return -1;
        return temp[amount];
    }
};