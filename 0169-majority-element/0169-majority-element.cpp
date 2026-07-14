class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int s;
        for(int i=0;i<n;i++){
            if(c==0){
                s=nums[i];
                c=1;
            }
            else if(s==nums[i])c++;
            else{
                c--;
            }
            
        }
        c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==s)c++;
        }
        cout<<c;
        if(c>(n/2))return s;
        return -1;
    }
};