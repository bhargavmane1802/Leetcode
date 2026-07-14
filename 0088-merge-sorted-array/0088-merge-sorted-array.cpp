class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int x=n+m-1;
        int l=n-1;
        if(m==0 )return;
        int r=m-1;
        while(l>=0 && r>=0){
            if(nums1[l]>nums2[r]){
                nums1[x]=nums1[l];
                l--;
            }
            else {
                nums1[x]=nums2[r];
                r--;
            }
            x--;
        }
        while(l>=0){
            nums1[x]=nums1[l];
            l--;
            x--;
        }
        while(r>=0){
            nums1[x]=nums2[r];
            r--;
            x--;
        }
        return ;
    }
};