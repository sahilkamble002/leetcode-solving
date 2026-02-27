class Solution {
public:
unordered_map<int,int>dp;
int mincost(int n, vector<int>& cost){
    if(n <= 1){
            return 0;
        }
        
        if(dp.count(n)){
            return dp[n];
        }

        int downone = cost[n-1]+ mincost(n-1,cost);
        int downtwo = cost[n-2]+ mincost(n-2,cost);
        dp[n] = min(downone,downtwo);
        return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
        return mincost(cost.size(),cost);
    }
};