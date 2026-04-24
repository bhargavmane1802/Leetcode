class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int x=0;
        for(int i=0;i<moves.size();i++){
            if('L'==moves[i]){
                l++;
            }
            else if('R'==moves[i]){
                r++;
            }
            else{
                x++;
            }
        }
        if(l>r){
            return l+x-r;
        }
        return r+x-l;
    }
};