#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int reverse(int x)
{
    try
    {
        bool negative{false};
        // check if x is negative
        if (x < 0)
        {
            negative = true;
        }
        string str{to_string(x)};
        string reverse_str;
        bool ignore{true};
        // reverse the string
        for (auto it{str.rbegin()}; it != str.rend(); it++)
        {
            if (*it != '0')
            {
                ignore = false;
            }
            if (!ignore)
            {
                reverse_str.push_back(*it);
            }
        }
        // convert to int and turn to negative if x was negative
        int reverse{negative == false ? stoi(reverse_str) : stoi(reverse_str) * -1};
        return reverse;
    }
    catch (const out_of_range &oor)
    {
        return 0;
    }
    catch (const invalid_argument &ia)
    {
        return 0;
    }
}

int main()
{
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
    cout << reverse(1534236469) << endl;
    return 0;
}