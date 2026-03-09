class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>f;
        for(int it : nums){
            f[it]++;
        }

        vector<vector<int>>bucket(n+1);

        for(auto &[x,c]: f){
            bucket[c].push_back(x);
        }
        vector<int> ans;

        for(int i = bucket.size()-1; 1 >= 0 && ans.size()<k; i--){
            for(int x :bucket[i]){
                ans.push_back(x);
                if(ans.size() == k)return ans;
            }
        }
        return ans;
    }
};