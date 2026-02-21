class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char, char>map = {
            {')', '('}, 
            {'}', '{'},
            {']','['}
            };

            for(char ch : s){
                if(map.count(ch) == 0){
                    st.push(ch);
                }else{
                    if(st.empty() || st.top() != map[ch]){
                        return false;
                    }
                    st.pop();
                }
            }
            return st.empty();
        
    }
};