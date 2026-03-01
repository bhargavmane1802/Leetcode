class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)return true;
        if(flowerbed.size()==1 && flowerbed[0]==1)return false;
        if(flowerbed.size()==1 && flowerbed[0]==0)return true;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==1){
                i++;
                continue;
            }
            if(i==0){
                if(flowerbed[i+1]==0){
                    flowerbed[0]=1;
                    n--;
                    i++;}
            }
            else if(i==flowerbed.size()-1){
                if(flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            else{
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    n--;
                    flowerbed[i]=1;
                    i++;
                }
            }
        }
        if(n==0)return true;
        else return false;
    }
};