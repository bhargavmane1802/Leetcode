class Solution {
public:
    int evalRPN(vector<string>& nums) {
       stack<int>s;
       for(string n:nums){
        if(n=="+"){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            x+=y;
            s.push(x);
        }
        else if(n=="-"){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            y-=x;
            s.push(y);
        }
        else if(n=="*"){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            x*=y;
            s.push(x);
        }
        else if(n=="/"){
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            y/=x;
            s.push(y);
        }
        else {
            s.push(stoi(n));
        }
       }
return s.top();
    }
};