class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto can = [&](long long T) {
        long long total = 0;

        for (int t : workerTimes) {
            long long val = (2 * T) / t;
            long long x = (-1 + sqrt(1 + 4 * val)) / 2;
            total += x;

            if (total >= mountainHeight) return true;
        }

        return false;
    };

    long long left = 1, right = 1e18, ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (can(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
    }
};