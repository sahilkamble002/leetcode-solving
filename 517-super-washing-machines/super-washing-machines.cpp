class Solution {
public:
    int findMinMoves(vector<int>& machines) {
    int n = machines.size();
    int total = accumulate(machines.begin(), machines.end(), 0);

    if (total % n != 0) return -1;

    int target = total / n;
    int result = 0;
    int flow = 0; 

    for (int i = 0; i < n; i++) {
        flow += machines[i] - target;

        
        result = max(result, max(abs(flow), machines[i] - target));
    }

    return result;
    }
};