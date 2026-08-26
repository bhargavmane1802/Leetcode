class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(s[i]=='1')temp.push_back(i);
        }
        if(temp.size()<k)return "";
        int t=INT_MAX;
        for(int i=0;i<=temp.size()-k;i++){
            t=min(temp[i+k-1]-temp[i]+1,t);
        }
        vector<string>nums;
        for(int i=0;i<=temp.size()-k;i++){
            if((temp[i+k-1]-temp[i]+1)==t){
                nums.push_back(s.substr(temp[i],t));
            }
        }
        sort(nums.begin(),nums.end());
        return nums[0];

    }
};