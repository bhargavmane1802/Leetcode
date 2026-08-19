class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {

        unordered_map<int, int> mp;

        for(auto x : r) {
            int row = x[0];
            int seat = x[1];

            if(seat >= 2 && seat <= 5)
                mp[row] |= 1;

            if(seat >= 4 && seat <= 7)
                mp[row] |= 2;

            if(seat >= 6 && seat <= 9)
                mp[row] |= 4;
        }

        int ans = (n - mp.size()) * 2;

        for(auto [row, mask] : mp) {

            bool left  = !(mask & 1);
            bool middle = !(mask & 2);
            bool right = !(mask & 4);

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};