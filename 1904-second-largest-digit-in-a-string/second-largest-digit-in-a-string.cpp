class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int second_largest = -1;

        for(char ch : s){
            if (isdigit(ch)){
                int num = ch - '0';
            if(num > largest){
                second_largest = largest;
                largest = num;
            }
            else if(num > second_largest && num != largest){
                second_largest = num;
            }
            }
        }
        return second_largest;
    }
};