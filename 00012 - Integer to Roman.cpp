class Solution {
public:
    string intToRoman(int num) {
        static vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        for (int i = 0; i < 13; i++) {
            int times = num / value[i];
            while (times--) {
                result += symbol[i];
            }
            num %= value[i];
        }
        return result;
    }
};
