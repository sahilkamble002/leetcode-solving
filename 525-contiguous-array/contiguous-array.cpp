class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
    mp[0] = -1; // important

    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        // convert 0 → -1
        if (nums[i] == 0) sum += -1;
        else sum += 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return maxLen;
    }
};