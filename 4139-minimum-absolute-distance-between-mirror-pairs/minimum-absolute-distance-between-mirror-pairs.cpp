class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
    auto reverseNum = [](int x) -> int {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    };

    unordered_map<int, int> lastSeenByRev;
    int minDist = INT_MAX;

    for (int i = 0; i < (int)nums.size(); i++) {
        int rev = reverseNum(nums[i]);

        // Find prior j where reverse(nums[j]) == nums[i]
        if (lastSeenByRev.count(nums[i])) {
            minDist = min(minDist, i - lastSeenByRev[nums[i]]);
        }

        
        lastSeenByRev[rev] = i;
    }

    return minDist == INT_MAX ? -1 : minDist;
}
};