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
        string ans;
        for(int i=0;i<=temp.size()-k;i++){
            int l=temp[i+k-1]-temp[i]+1;
            string curr=s.substr(temp[i],l);
            if(l<t){
                ans=curr;
                t=l;
            }
            else if (l==t && curr<ans){
                ans=curr;
            }
        }
        
        
        return ans;

    }
};