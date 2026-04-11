class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++)
            positions[nums[i]].push_back(i);
        
        int result = INT_MAX;
        
        for (auto& [val, idx] : positions) {
            if (idx.size() < 3) continue;
            
            // Slide a window of 3 consecutive indices
            for (int i = 0; i + 2 < idx.size(); i++)
                result = min(result, 2 * (idx[i+2] - idx[i]));
        }
        
        return result == INT_MAX ? -1 : result;
    }
};