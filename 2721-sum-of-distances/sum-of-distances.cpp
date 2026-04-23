class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
    vector<long long> res(n, 0);

    unordered_map<int, vector<int>> mp;

    // Step 1: store indices
    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    // Step 2: process each group
    for (auto &it : mp) {
        vector<int> &idx = it.second;
        int m = idx.size();

        vector<long long> prefix(m, 0);
        prefix[0] = idx[0];

        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + idx[i];
        }

        for (int i = 0; i < m; i++) {
            long long left = 0, right = 0;

            if (i > 0) {
                left = (long long)idx[i] * i - prefix[i - 1];
            }

            if (i < m - 1) {
                right = (prefix[m - 1] - prefix[i]) - (long long)idx[i] * (m - i - 1);
            }

            res[idx[i]] = left + right;
        }
    }

    return res;
    }
};