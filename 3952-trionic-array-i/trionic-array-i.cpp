class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        if( n < 4){
            return false;
        }

        int i =0;

        //increasing phase
        while(i+1 < n && nums[i+1]>nums[i]){
            i++;
        }
        if(i==0 || i == n-1){
            return false;
        }
        int peak = i;

        //decreasing phase
        while(i+1 < n && nums[i+1] < nums[i]){
            i++;
        }
        if(i == peak || i == n-1){
            return false;
        }
        //increasing phase
        while(i+1 < n && nums[i+1]>nums[i]){
            i+= 1;
        }
        return i == n-1;
    }
};