class StockSpanner {
public:
    stack<pair<int,int>>temp;
    StockSpanner() {
    }
    
    int next(int p) {
        int ans=1;
        while(!temp.empty() && temp.top().first<=p){
            ans+=temp.top().second;
            temp.pop();
        }
        temp.push({p,ans});
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */