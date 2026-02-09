class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int max_length = 0;

        while( right < n){
            if((long long)nums[right] <= (long long)nums[left]*k){
                max_length = max(max_length, right - left +1);
                right += 1;
            }
            else{
                left += 1;
            }
        }
        return n- max_length;
    }
};