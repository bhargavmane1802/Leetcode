class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int x=n;
        n=n+m;
        while(x!=0 && m!=0){
            if(nums1[x-1]>nums2[m-1]){
                nums1[n-1]=nums1[x-1];
                x--;
            }
            else{
                nums1[n-1]=nums2[m-1];
                m--;
            }
            n--;
        }
        while(m!=0){
            nums1[n-1]=nums2[m-1];
            n--;m--;
        }

    }
};