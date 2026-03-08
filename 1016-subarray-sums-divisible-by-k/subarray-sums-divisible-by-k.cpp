class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0; 
        int result = 0;

        vector<int>ps(k);
        ps[0]=1;

        for(int it : nums){
            sum = (sum + it % k + k) % k;
            result += ps[sum];
            ps[sum]++;
        }
        return result;
    }
};