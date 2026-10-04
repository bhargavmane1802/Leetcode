class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](auto &a, auto &b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        });
        // return p;
        // for(auto x:p)cout<<x[0]<<"-"<<x[1]<<"  ";
        // cout<<endl;
        int n=p.size();
        for(int i=1;i<n;i++){
           int a=p[i][0];
           int b=p[i][1];
           if(b==0)continue;
           int x=0;
           int y=0;
           while(x<=b && y<i){
            if(p[y][0]>=a)x++;
            y++;
           }
           if(y==i && x<=b )continue;
           y--;
        //    cout<<i <<" "<<y<<endl;
           int t=i;
           while(y<t){
            swap(p[t],p[t-1]);
            t--;
           }
        }
        return p;
    }
};