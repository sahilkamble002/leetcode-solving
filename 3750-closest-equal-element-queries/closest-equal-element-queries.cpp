class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
    
    unordered_map<int, vector<int>> mp;
    
    // Step 1: store indices for each value
    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }
    
    vector<int> ans;
    
    // Step 2: process each query
    for (int q : queries) {
        int val = nums[q];
        auto &vec = mp[val];
        
        // only one occurrence
        if (vec.size() == 1) {
            ans.push_back(-1);
            continue;
        }
        
        // find position of q in vec
        int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
        
        int res = INT_MAX;
        
        // check previous
        int prev = vec[(pos - 1 + vec.size()) % vec.size()];
        int d1 = abs(q - prev);
        res = min(res, min(d1, n - d1));
        
        // check next
        int next = vec[(pos + 1) % vec.size()];
        int d2 = abs(q - next);
        res = min(res, min(d2, n - d2));
        
        ans.push_back(res);
    }
    
    return ans;
    }
};