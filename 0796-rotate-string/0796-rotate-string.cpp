class Solution {
public:
    bool solve(string &s , string &goal ,int x){
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]==goal[(x+i)%n])i++;
            else return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        //brute force is to shift and check , repeat till the lenght of the string .
        if(s.size()!=goal.size())return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(solve(s,goal,i))return true;
        }
        return false;
        
    }
};