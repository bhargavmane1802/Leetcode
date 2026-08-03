class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s=nums1.size()-1;
        int x=m-1;
        int y=n-1;
        while(x>=0 && y>=0){
            if(nums1[x]>nums2[y]){
                nums1[s]=nums1[x];
                x--;
                s--;
            }
            else{
                nums1[s]=nums2[y];
                y--;
                s--;
            }
        }
        while(x>=0){
            nums1[s]=nums1[x];
                x--;
                s--;
        }
        while(y>=0){
            nums1[s]=nums2[y];
                y--;
                s--;
        }
        return ;
    }
};