class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.assign(n, 0);

        // initialize DSU
        for (int i = 0; i < n; i++) parent[i] = i;

        // build components
        for (auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }

        // group indices by root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int hamming = 0;

        // process each component
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match target values
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    hamming++;
                }
            }
        }

        return hamming;
    }
};