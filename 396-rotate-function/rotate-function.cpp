class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate sum and F(0)
        long long sum = 0, F = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }
        
        long long maxF = F;
        
        
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxF = max(maxF, F);
        }
        
        return (int)maxF;
    }
};