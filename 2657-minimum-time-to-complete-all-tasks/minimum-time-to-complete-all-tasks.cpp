class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });

    
    vector<int> used(2001, 0);

    int total = 0;

    for (auto &t : tasks) {
        int start = t[0], end = t[1], duration = t[2];


        int already = 0;
        for (int i = start; i <= end; i++) {
            if (used[i]) already++;
        }

        int need = duration - already;

        for (int i = end; i >= start && need > 0; i--) {
            if (!used[i]) {
                used[i] = 1;
                total++;
                need--;
            }
        }
    }

    return total;
    }
};