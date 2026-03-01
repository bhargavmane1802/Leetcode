class Solution {
public:
    int minPartitions(string n) {
        int x=-1;
        for(int i=0;i<n.size();i++){
            int temp=n[i]-'0';
            if(x<temp)x=temp;
        }
        return x;
        
    }
};