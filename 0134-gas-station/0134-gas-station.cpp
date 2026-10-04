class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int fuel=0;
     int n=gas.size();
     int total=0;
     int start=0;
     for(int i=0;i<n;i++){
        total+=(gas[i]-cost[i]);
        fuel+=(gas[i]-cost[i]);
        if(fuel<0){
            fuel=0;
            start=i+1;
        }
     }   
     if(total>=0)return start;
     return -1;
    }
};