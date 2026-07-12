class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>temp;
        for(int i:arr){
            temp.insert(i);
        }
        unordered_map<int,int>mp;
        int x=0;
        for (int i:temp){
            x++;
            mp[i]=x;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};