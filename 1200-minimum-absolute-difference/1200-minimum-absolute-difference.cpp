class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mind=INT_MAX;
        for(int i=1;i<n;i++){
            mind=min(mind,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==mind)ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
        
    }
};