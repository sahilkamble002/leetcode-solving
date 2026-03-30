class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();

    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({difficulty[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    int i = 0;
    int maxProfit = 0;
    int totalProfit = 0;

    for (int w : worker) {
        while (i < n && jobs[i].first <= w) {
            maxProfit = max(maxProfit, jobs[i].second);
            i++;
        }
        totalProfit += maxProfit;
    }

    return totalProfit;
    }
};