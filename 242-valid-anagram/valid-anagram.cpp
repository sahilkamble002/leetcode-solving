class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != s.length()){
            return false;
        }
        
        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch-'a']++;
        }
        for(char cz: t){
            freq[cz - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};