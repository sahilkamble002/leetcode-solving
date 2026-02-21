class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> count(1001, 0);

        for(auto &arr : nums){
            for(int val : arr){
                count[val]++;
            }
        }

        vector<int> ans;
        for(int i = 1; i < 1001; i++){
            if(count[i] == n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};