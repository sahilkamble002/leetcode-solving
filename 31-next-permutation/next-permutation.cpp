class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int breakeven = -1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                breakeven = i;
                break;
            }
        }

        if(breakeven == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i >= 0; i--){
            if(nums[i] > nums[breakeven]){
                swap(nums[i], nums[breakeven]);
                break;
            }
        }
        reverse(nums.begin()+ breakeven+1, nums.end());
        
    }
};