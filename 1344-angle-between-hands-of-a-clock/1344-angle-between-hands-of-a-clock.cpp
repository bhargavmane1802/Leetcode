class Solution {
public:
    double angleClock(int h, int m) {
        double x=double(abs((30*h)-(5.5*m)));
        if(x>180)return 360.0-x;
        return x;
    }
};