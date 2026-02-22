class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posindex = 0;
        int negindex = 1;
        vector<int>result(n);
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                result[posindex] = nums[i];
                posindex +=2;
            }
            else{
                result[negindex] = nums[i];
                negindex += 2;
            }
        }
        return result;
    }
};