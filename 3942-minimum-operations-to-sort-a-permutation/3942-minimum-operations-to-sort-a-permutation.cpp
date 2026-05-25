class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                c++;
                ans=i;
            }
            if(c==1 && nums[i]>nums[0]){c++;
            }
            if(c>1)break;
        }
        if(c==0)return 0;
        if(c==1)return min(ans,n+2-ans);
        c=0;ans=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                c++;
                ans=i;
            }
            if(c==1 && nums[i]<nums[0]){c++;
            }
            if(c>1)break;
        }
        ans++;
        if(c==0)return 1;
        if(c==1)return min(ans,n+2-ans);
        return -1;
    }
};