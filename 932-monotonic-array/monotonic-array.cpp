class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        bool dec = true;

        for(int i = 0; i < n-1; i++){
            if(nums[i+1] < nums[i]){
                inc = false;
            }
             if(nums[i+1] > nums[i]){
                dec = false;
            }
        }
        return inc || dec;
    }
};