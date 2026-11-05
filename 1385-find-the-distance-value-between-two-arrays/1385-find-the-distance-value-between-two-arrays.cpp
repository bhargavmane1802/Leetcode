class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count =0;
        for(int i:arr1){
            int x=1;
            for(int j:arr2){
                if(abs(i-j)<=d){
                    x=0;
                    break;
                }
            }
            if(x==1)count++;
        }
        return count;
    }
};