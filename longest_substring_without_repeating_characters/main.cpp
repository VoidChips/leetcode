#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    string temp;

    int length{0};
    for (const auto &c : s)
    {
        if (temp.find(c) != string::npos)
        {
            int another{lengthOfLongestSubstring(s.substr(s.find(c) + 1))};
            return length >= another
                       ? length
                       : another;
        }
        temp += c;
        length++;
    }
    return length;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}