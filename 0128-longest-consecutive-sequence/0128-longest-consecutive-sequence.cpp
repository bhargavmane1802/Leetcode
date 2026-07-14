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
                int c=0;
                while(temp.find(x)!=temp.end()){
                    temp.erase(x);
                    c++;
                    x--;
                }
                x=i+1;
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
