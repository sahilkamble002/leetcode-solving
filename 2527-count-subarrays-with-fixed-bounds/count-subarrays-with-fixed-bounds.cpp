class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

    int lastMin = -1, lastMax = -1, lastBad = -1;

    for (int i = 0; i < nums.size(); i++) {

        // invalid element
        if (nums[i] < minK || nums[i] > maxK) {
            lastBad = i;
        }

        if (nums[i] == minK) lastMin = i;
        if (nums[i] == maxK) lastMax = i;

        int validEnd = min(lastMin, lastMax);

        if (validEnd > lastBad) {
            ans += (validEnd - lastBad);
        }
    }

    return ans;
    }
};