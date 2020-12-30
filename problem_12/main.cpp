#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // converts multiples of 10, 9, 5, or 4 to a roman numeral
    void intToRomanForDigit(int &num, string &roman, const vector<string> &r_numerals, const int &multiples)
    {
        int x{};

        if (num >= 10 * multiples)
        {
            x = num / (10 * multiples);
            num -= x * 10 * multiples;
            for (int i{}; i < x; i++)
            {
                roman += r_numerals[0];
            }
        }
        else if (num >= 9 * multiples)
        {
            num -= 9 * multiples;
            roman += r_numerals[1];
        }
        else if (num >= 5 * multiples)
        {
            num -= 5 * multiples;
            roman += r_numerals[2];
        }
        else if (num >= 4 * multiples)
        {
            num -= 4 * multiples;
            roman += r_numerals[3];
        }
    }

    // converts a number between 1 and 3999 inclusive to roman numeral
    string intToRoman(int num)
    {
        string roman;

        if (num >= 1000)
        {
            int x{};
            x = num / 1000;
            num -= x * 1000;
            for (int i{}; i < x; i++)
            {
                roman += "M";
            }
        }

        if (num >= 900)
        {
            num -= 900;
            roman += "CM";
        }
        else if (num >= 500)
        {
            num -= 500;
            roman += "D";
        }
        else if (num >= 400)
        {
            num -= 400;
            roman += "CD";
        }

        intToRomanForDigit(num, roman, vector<string>{"C", "XC", "L", "XL"}, 10);
        // convert leftover num
        if (num == 9 || num >= 5 || num == 4) {
            intToRomanForDigit(num, roman, vector<string>{"C", "XC", "L", "XL"}, 10);
        }

        intToRomanForDigit(num, roman, vector<string>{"X", "IX", "V", "IV"}, 1);
        if (num == 9 || num >= 5 || num == 4) {
            intToRomanForDigit(num, roman, vector<string>{"X", "IX", "V", "IV"}, 1);
        }

        if (num >= 1)
        {
            for (int i{}; i < num; i++)
            {
                roman += "I";
            }
        }

        return roman;
    }
};

int main()
{
    Solution a;
    cout << "3: " << a.intToRoman(3) << endl;
    cout << "4: " << a.intToRoman(4) << endl;
    cout << "9: " << a.intToRoman(9) << endl;
    cout << "58: " << a.intToRoman(58) << endl;
    cout << "1994: " << a.intToRoman(1994) << endl;
    cout << "10: " << a.intToRoman(10) << endl;
    cout << "8: " << a.intToRoman(8) << endl;
    cout << "19: " << a.intToRoman(19) << endl;
    cout << "137: " << a.intToRoman(137) << endl;
    cout << "3999: " << a.intToRoman(3994) << endl;
    cout << "14: " << a.intToRoman(14) << endl;
    cout << "140: " << a.intToRoman(140) << endl;
    cout << "2789: " << a.intToRoman(2789) << endl;
    return 0;
}
