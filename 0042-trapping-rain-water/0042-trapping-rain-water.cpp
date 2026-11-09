class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            l=max(l,height[i]);
            left[i]=l;
        }
        for(int i=n-1;i>=0;i--){
            r=max(r,height[i]);
            right[i]=r;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(left[i],right[i]);
            if(height[i]<x)ans+=(x-height[i]);
        }
        return ans;
    }
};