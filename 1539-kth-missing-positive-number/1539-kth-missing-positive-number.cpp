class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int n=arr.size();
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((arr[mid]-(mid+1))<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(l!=0){
            l--;
            int x=arr[l]+k-(arr[l]-(l+1));
            return x;
        }
        return k;
    }
};