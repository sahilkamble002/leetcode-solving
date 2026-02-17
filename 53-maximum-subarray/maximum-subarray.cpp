class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        int ansstart = -1;
        int ansend = -1;
        int start = 0;

        for(int it = 0; it < nums.size(); it++){
             
            if(sum ==0){
                start = it;
            }
            sum +=nums[it];

            if(sum > maxsum){
                maxsum = sum;
                ansstart = start;
                ansend = it;
            }

            if(sum < 0)sum = 0;
        }
        return maxsum;
    }
};