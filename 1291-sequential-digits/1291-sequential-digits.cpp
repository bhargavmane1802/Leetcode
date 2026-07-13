class Solution {
public:
    void gen(int low, int high,vector<int> &ans,string s,unordered_set<int>&temp){
        int x=stoi(s);
        if(temp.find(x)==temp.end()){
            temp.insert(x);
        }
        else return;
        if(x>high)return ;
        if(x>=low && x<=high){
            ans.push_back(x);
        }
        string t=s;
        int last=s[s.size()-1]-'0';
        if(last!=9){
            t.erase(0,1);
            t.push_back(last+'1');
            gen(low,high,ans,t,temp);
            s.push_back(last+'1');
            gen(low,high,ans,s,temp);
        }


    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        unordered_set<int>temp;
        gen(low,high,ans,"12",temp);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};