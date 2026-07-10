class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({nums[i],i});

        sort(a.begin(),a.end());

        vector<int> pos(n);
        for(int i=0;i<n;i++)
            pos[a[i].second]=i;

        // next[i]
        vector<int> nxt(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n && a[j+1].first-a[i].first<=maxDiff)
                j++;
            nxt[i]=j;
        }

        const int LOG=18;

        vector<vector<int>> up(LOG,vector<int>(n));

        up[0]=nxt;

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q:queries){

            int l=pos[q[0]];
            int r=pos[q[1]];

            if(l>r) swap(l,r);

            if(l==r){
                ans.push_back(0);
                continue;
            }

            int cur=l;

            if(up[LOG-1][cur]<r){
                ans.push_back(-1);
                continue;
            }

            int dist=0;

            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur]<r){
                    dist+=(1<<k);
                    cur=up[k][cur];
                }
            }

            ans.push_back(dist+1);
        }

        return ans;
    }
};