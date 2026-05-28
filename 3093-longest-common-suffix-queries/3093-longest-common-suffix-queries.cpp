class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx;
        int bestLen;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
            bestLen = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node()); // root
    }

    void update(int node, int idx, int len) {
        if (len < trie[node].bestLen ||
           (len == trie[node].bestLen && idx < trie[node].bestIdx)) {
            trie[node].bestLen = len;
            trie[node].bestIdx = idx;
        }
    }

    void insert(const string &s, int idx) {
        int node = 0;
        int len = s.size();

        update(node, idx, len);

        for (int i = len - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            update(node, idx, len);
        }
    }

    int query(const string &s) {
        int node = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};