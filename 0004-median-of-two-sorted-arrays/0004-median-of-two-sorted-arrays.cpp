class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(m<n){swap(nums1,nums2);swap(n,m);}
        int median=(n+m+1)/2;
        int l=-1;
        int r=n;
        double ans=0.0;
        while(l<=r){
            int md=l+(r-l)/2;
            int la=INT_MIN,ra=INT_MAX;
            int lb=INT_MIN,rb=INT_MAX;
            if(md>=0){
                la=nums1[md];
            }
            if(md+1<n){
                ra=nums1[md+1];
            }
            int x=median-md-2;
            if(x>=0){
                lb=nums2[x];
            }
            if(x+1<m){
                rb=nums2[x+1];
            }
            if(la<=rb && lb<=ra){
                if((m+n)%2==0){
                    return (max(lb+0.0,la+0.0)+min(ra+0.0,rb+0.0))/2;
                }
                else return max(lb+0.0,la+0.0);
            }
            else if(la>rb) r=md-1;
            else l=md+1;
        }
        return 0.0;
    }
};