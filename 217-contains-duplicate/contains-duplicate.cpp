class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;

        for(int num : nums){
            if(seen.find(num) != seen.end()){
                return true;
            }
            seen.insert(num);
        }
        return false;
        
    }
};