class Solution {
public:
    bool solve(int i,unordered_map<int,int>&valid ,unordered_set<int>&invalid){
        int num=0;
        int unit=0;
        int x=0;
        int temp=i;
        while(i>0){
            unit=i%10;
            i=i/10;
            if(invalid.find(unit)!=invalid.end())return false;
            num=num+(valid[unit]*pow(10,x));
            x++;
        }
        if(num==temp)return false;
        return true;

    }
    int rotatedDigits(int n) {
        int ans=0;
        unordered_set<int>invalid;
        invalid.insert(3);
        invalid.insert(4);
        invalid.insert(7);
        unordered_map<int,int>valid;
        valid[0]=0;
        valid[1]=1;
        valid[2]=5;
        valid[5]=2;
        valid[6]=9;
        valid[8]=8;
        valid[9]=6;
        for(int i=1;i<=n;i++){
            if(solve(i,valid,invalid))ans++;
        }
        return ans;
    }
};