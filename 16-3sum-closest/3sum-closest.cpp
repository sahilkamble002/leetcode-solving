class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closest_sum = nums[0]+nums[1]+nums[2];

        for(int i = 0; i < n-2; i++){
            
            int left = i+1; 
            int right = n-1;
             
            while(left < right){
                int curr_sum = nums[i]+nums[left]+nums[right];

                if(abs(curr_sum - target) < abs(closest_sum - target)){
                    closest_sum = curr_sum;
                }

                else if(curr_sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return closest_sum;
    }
};