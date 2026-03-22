class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first, last;
    
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        
        if (!first.count(x)) first[x] = i;  
        last[x] = i;                        
        count[x]++;
    }
    
    int degree = 0;
    for (auto &p : count) {
        degree = max(degree, p.second);
    }
    
    int ans = nums.size();
    
    for (auto &p : count) {
        int x = p.first;
        if (p.second == degree) {
            int len = last[x] - first[x] + 1;
            ans = min(ans, len);
        }
    }
    
    return ans;

    }
};