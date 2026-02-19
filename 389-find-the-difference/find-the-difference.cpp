class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for(char ch : s){
            result = result ^ch;
        }
        for(char cz : t){
            result = result^cz;
        }
        return result;
    }
};