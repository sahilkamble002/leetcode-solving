class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int n = nums.size();
        int max_val = 0;
        int minIncrement = 0;

        for(int val : nums){
            max_val = max(max_val,val);
        }
        vector<int> frequency(n+ max_val, 0);

        for(int val: nums){
            frequency[val]++;
        }

        for(int i = 0;i < frequency.size(); i++){
            if(frequency[i] <= 1)continue;

            int duplicate = frequency[i] -1;
            frequency[i+1] += duplicate;
            frequency[i] = 1;
            minIncrement += duplicate;
        }
        return minIncrement;
        
    }
};