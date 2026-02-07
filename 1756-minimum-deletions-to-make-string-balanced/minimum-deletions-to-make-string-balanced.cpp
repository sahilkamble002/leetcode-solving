class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int delection = 0;

        for(char ch : s){
            if(ch == 'a'){
                delection = min(delection+1, b_count);
            }
            else{
                b_count +=1;
            }
        }
        return delection;
        
    }
};