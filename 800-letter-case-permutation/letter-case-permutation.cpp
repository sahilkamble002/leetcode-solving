class Solution {
public:

vector<string>ans;
void solve(string &s, int i, string &x) {
    // base case
    if (i == s.size()) {
        ans.push_back(x);
        return;
    }

    if (isalpha(s[i])) {
        // lowercase
        x.push_back(tolower(s[i]));
        solve(s, i + 1, x);
        x.pop_back();

        // uppercase
        x.push_back(toupper(s[i]));
        solve(s, i + 1, x);
        x.pop_back();
    } else {
        // digit
        x.push_back(s[i]);
        solve(s, i + 1, x);
        x.pop_back();
    }
}
    vector<string> letterCasePermutation(string s) {
       ans.clear();
    string x = "";
    solve(s, 0, x);
    return ans;
    }
};