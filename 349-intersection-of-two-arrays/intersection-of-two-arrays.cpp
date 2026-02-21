class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        int i = 0;
        int j = 0;
        vector<int>result;

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else {
                if(result.empty() || result.back() != nums1[i]){
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return result;
    }
};