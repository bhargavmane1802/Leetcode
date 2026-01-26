class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>temp;
        int ans=0;
        for(int i:nums)temp.insert(i);
        for(int i :nums){
            if(temp.find(i)==temp.end())continue;
            else{
                int x=i;
                while(temp.find(x)!=temp.end()){
                    x--;
                }
                int c=0;
                x++;
                while(temp.find(x)!=temp.end()){
                    temp.erase(x);
                    c++;
                    x++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};