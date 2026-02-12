class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++){
        vector<int>freq(26,0);
        int distinct = 0;
        int maxfreq = 0;

        for(int j = i; j < n; j++){
            int ind = s[j]-'a';
            
            if(freq[ind] == 0)distinct++;

            freq[ind]++;
            maxfreq = max(maxfreq,freq[ind]);
            int len = j-i+1;

            if(len == distinct*maxfreq){
                ans = max(ans,len);
            }
        }
        }
        return ans;
    }
};