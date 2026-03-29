class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<char>even1;
        vector<char>odd1;
        vector<char>even2;
        vector<char>odd2;
        for(int i=0;i<4;i++){
            if(i%2==0){
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            }
            else{
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            }
        }
        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        if(even1==even2 && odd1==odd2)return true;
        return false;
        
    }
};