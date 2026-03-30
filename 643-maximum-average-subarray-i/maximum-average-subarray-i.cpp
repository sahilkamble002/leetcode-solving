class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    
    
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    double maxSum = sum;

    // Step 2: slide window
    for (int i = k; i < n; i++) {
        sum += nums[i];        // add next element
        sum -= nums[i - k];    // remove previous element
        
        maxSum = max(maxSum, sum);
    }

    // Step 3: return average
    return maxSum / k;    
    }
};