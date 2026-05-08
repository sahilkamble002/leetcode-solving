
class Solution {
public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; i++)
            if (isPrime[i])
                for (int j = i * i; j <= maxVal; j += i)
                    isPrime[j] = false;
        return isPrime;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime = sieve(maxVal);

        // For each prime p that appears as nums[i], collect indices reachable by teleport
        // teleportTo[p] = all indices j where nums[j] % p == 0
        // No longer gated on primeToIndices — any divisible index is a valid target
        unordered_map<int, vector<int>> teleportTo;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int orig = val;
            for (int p = 2; (long long)p * p <= val; p++) {
                if (orig % p == 0 && isPrime[p]) {
                    teleportTo[p].push_back(i);  // ✅ no primeToIndices guard
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1 && isPrime[val]) {
                teleportTo[val].push_back(i);    // ✅ no primeToIndices guard
            }
        }

        // BFS
        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrimes;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int d = dist[cur];

            if (cur == n - 1) return d;

            // Adjacent steps
            for (int next : {cur - 1, cur + 1}) {
                if (next >= 0 && next < n && dist[next] == -1) {
                    dist[next] = d + 1;
                    q.push(next);
                }
            }

            // Prime Teleportation
            int p = nums[cur];
            if (isPrime[p] && !usedPrimes.count(p)) {
                usedPrimes.insert(p);
                for (int next : teleportTo[p]) {
                    if (dist[next] == -1) {
                        dist[next] = d + 1;
                        q.push(next);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};