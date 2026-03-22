class Solution {
public:string result = "";
    int count = 0;
    
    void solve(int n, int k, string &curr) {
        if (curr.size() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (!curr.empty() && curr.back() == ch) continue;
            
            curr.push_back(ch);
            solve(n, k, curr);
            curr.pop_back();
            
            if (!result.empty()) return; // early stop
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return result;
    }
};