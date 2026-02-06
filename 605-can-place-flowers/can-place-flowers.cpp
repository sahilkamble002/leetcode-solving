class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int t = flowerbed.size();

        for(int i = 0; i < t; i++){
            if(flowerbed[i] == 0){
                bool emptyleft = (i == 0) || (flowerbed[i-1] == 0);
                bool emptyright = (i == t-1) || (flowerbed[i+1] == 0);

                if(emptyleft && emptyright){
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};