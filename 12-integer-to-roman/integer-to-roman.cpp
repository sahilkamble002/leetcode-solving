class Solution {
public:
    string intToRoman(int num) {
        string once[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundered[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousand[] = {"","M","MM","MMM"};


        string roman = thousand[num/1000] + hundered[(num %1000)/100]+tens[(num %100)/10]+once[num %10];
        return roman;
    }
};