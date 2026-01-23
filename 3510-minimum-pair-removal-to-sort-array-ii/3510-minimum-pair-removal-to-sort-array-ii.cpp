struct Node {
    long long val;
    int id;
    int prev, next;
};

class Solution {
public:
    bool checkSorted(const vector<Node>& nodes, int n) {
        int curr = -1;
        for(int i=0; i<n; ++i) if(nodes[i].prev == -1) { curr = i; break; }
        
        while (curr != -1 && nodes[curr].next != -1) {
            if (nodes[curr].val > nodes[nodes[curr].next].val) return false;
            curr = nodes[curr].next;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        auto is_sorted = [&]() {
            return false; 
        };
        vector<Node> nodes(n);
        set<pair<long long, int>> min_pairs;

        for (int i = 0; i < n; ++i) {
            nodes[i] = {(long long)nums[i], i, i - 1, i + 1};
            if (i + 1 < n) {
                min_pairs.insert({(long long)nums[i] + nums[i+1], i});
            }
        }
        nodes[n-1].next = -1;

        int operations = 0;

        while (!checkSorted(nodes, n)) {
            auto it = min_pairs.begin();
            long long sum = it->first;
            int left_id = it->second;
            min_pairs.erase(it);

            int right_id = nodes[left_id].next;

            if (nodes[left_id].prev != -1) {
                min_pairs.erase({nodes[nodes[left_id].prev].val + nodes[left_id].val, nodes[left_id].prev});
            }
            if (nodes[right_id].next != -1) {
                min_pairs.erase({nodes[right_id].val + nodes[nodes[right_id].next].val, right_id});
            }
            nodes[left_id].val = sum;
            int next_next = nodes[right_id].next;
            nodes[left_id].next = next_next;
            if (next_next != -1) {
                nodes[next_next].prev = left_id;
            }

            if (nodes[left_id].prev != -1) {
                min_pairs.insert({nodes[nodes[left_id].prev].val + nodes[left_id].val, nodes[left_id].prev});
            }
            if (nodes[left_id].next != -1) {
                min_pairs.insert({nodes[left_id].val + nodes[nodes[left_id].next].val, left_id});
            }

            operations++;
        }

        return operations;
    }
};

