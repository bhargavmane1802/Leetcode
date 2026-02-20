class Trie {
public:
    vector<pair<char,Trie*>>store;
    Trie() {
    }
    
    void insert(string word) {
        solve(0, word,this);
    }
    
    bool search(string word) {
        word=word+'$';
        return check(0,word,this);        
    }
    
    bool startsWith(string prefix) {
        return check(0,prefix,this);
    }
    void solve(int i,string &s,Trie *root){
        if(i>=s.size()){
            root->store.push_back({'$',NULL});
            return ;
        }
        for(auto x:root->store){
            if(x.first==s[i]){
                if(!x.second)return;
                solve(i+1,s,x.second);
                return;
            }
        }
        Trie*node=new Trie();
        root->store.push_back({s[i],node});
        solve(i+1,s,node);
        return;
    }
    bool check(int i,string & s,Trie * root){
        if(i>=s.size()){
            return true;
        }
        if(!root)return false;
        for(auto x:root->store){
            if(x.first==s[i]){
                return check(i+1,s,x.second);
            }
        }
        return false;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */