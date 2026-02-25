class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        int currsum = 1;
        if(n == 1){
            return nums[n-1];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                currsum= 1;
                continue;

            }

            currsum *= nums[i];
            maxsum = max(maxsum, currsum);
        }

        currsum = 1;

        for(int i = n-1; i >= 0; i--){
            if(nums[i] == 0){
                currsum= 1;
             continue;
            }

            currsum *= nums[i];
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};