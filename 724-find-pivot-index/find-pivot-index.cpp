class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum +=nums[i];
        }
        //int index = 0;
        int left_sum = 0;

        for(int i = 0; i < n; i++){
            //int running_sum = nums[i];
            int right_sum = sum - left_sum - nums[i];
            if(left_sum == right_sum){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};