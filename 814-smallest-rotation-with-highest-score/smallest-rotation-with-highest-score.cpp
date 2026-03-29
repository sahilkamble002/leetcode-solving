class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;

            diff[low] += 1;
            diff[high] -= 1;

            if (low >= high) {
                diff[0] += 1;
            }
        }

        int maxScore = -1, bestK = 0;
        int score = 0;

        for (int k = 0; k < n; k++) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }

        return bestK;
    }
};