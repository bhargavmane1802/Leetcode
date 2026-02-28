class Solution {
public:
    string frequencySort(string s) {
        vector<long long>temp(122);
        for(char i:s){
            temp[int(i-'0')]++;
        }
        vector<pair<long long,char>>store;
        for(int i=0;i<122;i++){
            if(temp[i]==0)continue;
            store.push_back({temp[i],char('0'+i)});
        }
        sort(store.rbegin(),store.rend());
        string ans="";
        for(auto x:store){
            for(int i=0;i<x.first;i++){
                ans.push_back(x.second);
            }
        }
        return ans;

        
    }
};