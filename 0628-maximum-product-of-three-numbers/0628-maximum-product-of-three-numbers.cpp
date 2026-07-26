class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>q;
        priority_queue<int,vector<int>,greater<int>>g;
        for(int i=0;i<n;i++){
            if(q.size()<2){
                q.push(nums[i]);
            }
            else if(q.size()>=2 && q.top()>=nums[i]){
                q.pop();
                q.push(nums[i]);
            }
            if(g.size()<3){
                g.push(nums[i]);
            }
            else if(g.size()>=3 && g.top()<=nums[i]){
                g.pop();
                g.push(nums[i]);
            }
        }
        int x=q.top();
        q.pop();
        x*=q.top();
        int y=g.top();
        g.pop();
        y*=g.top();
        g.pop();
        x*=g.top();
        y*=g.top();

        int ans=max(x,y);
        return ans;
    }
};