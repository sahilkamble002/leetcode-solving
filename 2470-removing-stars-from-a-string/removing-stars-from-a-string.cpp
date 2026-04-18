class Solution {
public:
    string removeStars(string s) {
        string result = "";
        stack<char>st;

        for(char c: s){
            if(c == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};