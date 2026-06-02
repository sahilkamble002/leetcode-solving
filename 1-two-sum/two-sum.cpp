class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>>hs;
        for(int i = 0; i < n; i++){
            hs.push_back({nums[i],i});
        }

        sort(hs.begin(), hs.end());

        int i = 0;
        int j = n-1;

        while(i < j){
            int sum = hs[i].first + hs[j].first;
            if(sum == target){
                return {hs[i].second , hs[j].second};
            }

            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1, -1}; 
    }
};