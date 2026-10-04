class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0;//jump
        int last=0;
        int start=0;
        if(nums.size()==1)return 0;
        while(start<=last){
            j++;
            int temp=last;
            for(int i=start;i<=last;i++){
                temp=max(temp,i+nums[i]);
            }
            if(temp==last)return -1;
            start=last+1;
            last=temp;
            if(temp>=nums.size()-1)return j;
        }
        return -1;
    }
};