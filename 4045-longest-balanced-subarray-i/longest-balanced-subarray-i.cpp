class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int maxlength = 0;
        //triying all possible starting points;
        for(int i = 0; i < n; i++){
            unordered_set<int> even, odd;

            //starting form all possible points 
            for(int j =i; j < n; j++){
                if(nums[j] % 2 == 0){
                    even.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }

                //checking is balanced or not
                if(even.size() == odd.size()){
                    maxlength = max(maxlength, j-i+1);
                }
            }
        }
        return maxlength;
    }
};