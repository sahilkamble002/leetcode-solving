class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = 0;
        int sum2 = 0;

        for(auto it : aliceSizes){
            sum1 += it;
        }

        for(auto it : bobSizes){
            sum2 += it;
        }

        int diff = (sum1 - sum2)/2;

        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        int i =0;
        int j = 0;

        int n = aliceSizes.size();
        int m = bobSizes.size();

        while(i < n && j < m){
            if(aliceSizes[i] - bobSizes[j] > diff){
                j++;
            }
            else if(aliceSizes[i] - bobSizes[j] < diff){
                i++;
            }
            else{
                return {aliceSizes[i], bobSizes[j]};
            }
        }
        return {};
    }
};