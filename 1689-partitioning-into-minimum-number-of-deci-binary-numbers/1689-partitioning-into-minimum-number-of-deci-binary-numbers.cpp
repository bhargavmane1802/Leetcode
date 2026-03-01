class Solution {
public:
    int minPartitions(string n) {
        int x=-1;
        for(char i:n){
            if(x<i-'0')x=i-'0';
        }
        return x;
        
    }
};