class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxwater = 0;

        while(left < right){
            int width = right - left;

            int length = min(height[left] , height[right]);
            int current_water = width*length;

            maxwater = max(maxwater, current_water);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
};