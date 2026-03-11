class Solution {
public:
    string decodeString(string s) {
        stack<char>st;

        for(int i = 0; i < s.length(); i++){
            string decode;

            if(s[i] == ']'){
                while(st.top()!='['){
                decode.push_back(st.top());
                st.pop();
            }
            st.pop();
            int base = 1;
            int k = 0;
            while(!st.empty() && isdigit(st.top())){
                k+= (st.top()-'0')*base;
                st.pop();
                base *= 10;
            }
            reverse(decode.begin(), decode.end());

            while( k-- >0){
                for(char c :decode){
                    st.push(c);
                }
            }
            }

            else{
                st.push(s[i]);
            }
        }
        string result;
        result.reserve(st.size());
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};