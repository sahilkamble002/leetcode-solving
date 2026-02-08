class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        long long left_sum = 0;

        int count = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        for(int i = 0; i < n-1; i++){
            left_sum += nums[i];

            if(left_sum >= (sum-left_sum)){
                count++;
            }
        }
        return count;
    }
};