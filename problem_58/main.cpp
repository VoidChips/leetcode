#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length{};
        bool lastWordFound{false};

        for (size_t i{s.length()}; i > 0; i--)
        {
            if (s[i - 1] != ' ')
            {
                if (!lastWordFound)
                    lastWordFound = true;
                length++;
                continue;
            }

            if (lastWordFound)
                break;
        }

        return length;
    }

    void printInputAndOutput(const string &s)
    {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << lengthOfLastWord(s) << endl;
    }
};

int main()
{
    Solution a;

    a.printInputAndOutput("Hello World");
    a.printInputAndOutput(" ");
    a.printInputAndOutput("pancake");
    a.printInputAndOutput("This is a pancake");
    a.printInputAndOutput("a ");

    return 0;
}
