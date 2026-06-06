class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxwater = 0;

        while(i < j){
            int width = j-i;
            int length = min(height[i], height[j]);
            int currwater = length * width;

            maxwater = max(maxwater, currwater);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};