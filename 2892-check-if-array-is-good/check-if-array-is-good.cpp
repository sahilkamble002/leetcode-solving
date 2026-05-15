class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        if (nums.size() != n + 1) return false;
        
        vector<int> count(n + 1, 0);
        for (int x : nums) {
            if (x > n) return false;
            count[x]++;
        }
        
        for (int i = 1; i < n; i++)
            if (count[i] != 1) return false;
        
        return count[n] == 2;
    }
};