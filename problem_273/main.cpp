#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    // add space to string if it's not empty
    void addSpace(string &words)
    {
        if (!words.empty())
        {
            words += " ";
        }
    }

    // convert number to english words
    // 0 <= num <= 2^31 - 1
    string numberToWords(int num)
    {
        unordered_map<int, string> numbers;
        unordered_map<int, int> digits;
        vector<int> digit_groups(4); // break number into 4 groups
        string words;
        string num_str(to_string(num));
        size_t num_str_len{num_str.length()};

        numbers.emplace(0, "");
        numbers.emplace(1, "One");
        numbers.emplace(2, "Two");
        numbers.emplace(3, "Three");
        numbers.emplace(4, "Four");
        numbers.emplace(5, "Five");
        numbers.emplace(6, "Six");
        numbers.emplace(7, "Seven");
        numbers.emplace(8, "Eight");
        numbers.emplace(9, "Nine");
        numbers.emplace(10, "Ten");
        numbers.emplace(11, "Eleven");
        numbers.emplace(12, "Twelve");
        numbers.emplace(13, "Thirteen");
        numbers.emplace(14, "Fourteen");
        numbers.emplace(15, "Fifteen");
        numbers.emplace(16, "Sixteen");
        numbers.emplace(17, "Seventeen");
        numbers.emplace(18, "Eighteen");
        numbers.emplace(19, "Nineteen");
        numbers.emplace(20, "Twenty");
        numbers.emplace(30, "Thirty");
        numbers.emplace(40, "Forty");
        numbers.emplace(50, "Fifty");
        numbers.emplace(60, "Sixty");
        numbers.emplace(70, "Seventy");
        numbers.emplace(80, "Eighty");
        numbers.emplace(90, "Ninety");
        numbers.emplace(100, "Hundred");
        numbers.emplace(1000, "Thousand");
        numbers.emplace(1000000, "Million");
        numbers.emplace(1000000000, "Billion");

        digits.emplace(3, 100);
        digits.emplace(4, 1000);
        digits.emplace(7, 1000000);
        digits.emplace(10, 1000000000);

        if (num == 0)
        {
            return "Zero";
        }

        if (num_str_len <= 3)
        {
            digit_groups[3] = stoi(num_str);
        }
        else if (num_str_len <= 6)
        {
            digit_groups[2] = stoi(num_str.substr(0, num_str_len - 3));
            digit_groups[3] = stoi(num_str.substr(num_str_len - 3, 3));
        }
        else if (num_str_len <= 9)
        {
            digit_groups[1] = stoi(num_str.substr(0, num_str_len - 6));
            digit_groups[2] = stoi(num_str.substr(num_str_len - 6, 3));
            digit_groups[3] = stoi(num_str.substr(num_str_len - 3, 3));
        }
        else
        {
            stringstream ss;
            int x{};
            char c{num_str[0]};
            ss << c;
            ss >> x;
            digit_groups[0] = x;
            digit_groups[1] = stoi(num_str.substr(num_str_len - 9, 3));
            digit_groups[2] = stoi(num_str.substr(num_str_len - 6, 3));
            digit_groups[3] = stoi(num_str.substr(num_str_len - 3, 3));
        }

        for (int i{}; i < digit_groups.size(); i++)
        {
            int x{digit_groups[i]};

            if (x == 0)
            {
                continue;
            }

            if (x >= 100)
            {
                addSpace(words);
                words += numbers.at(x / 100);
                words += " " + numbers.at(digits.at(3));
                x -= 100 * (x / 100);
            }
            if (x >= 10 && x < 20)
            {
                addSpace(words);
                words += numbers.at(x);
                x -= x;
            }
            else if (x >= 20)
            {
                addSpace(words);
                words += numbers.at((x / 10) * 10);
                x -= 10 * (x / 10);
            }
            if (x != 0)
            {
                addSpace(words);
                words += numbers.at(x);
            }

            if (i != 3)
            {
                addSpace(words);
                words += numbers.at(digits.at(10 - i * 3));
            }
        }

        return words;
    }
};

int main()
{
    Solution a;
    cout << "123: " << a.numberToWords(123) << endl;
    cout << "12345: " << a.numberToWords(12345) << endl;
    cout << "1234567: " << a.numberToWords(1234567) << endl;
    cout << "1234567891: " << a.numberToWords(1234567891) << endl;
    cout << "0: " << a.numberToWords(0) << endl;
    cout << "4934: " << a.numberToWords(4934) << endl;
    cout << "523: " << a.numberToWords(523) << endl;
    cout << "9385903: " << a.numberToWords(9385903) << endl;
    return 0;
}
