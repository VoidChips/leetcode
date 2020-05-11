#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x)
{
    string str{to_string(x)};
    string reverse;
    for (auto it{str.rbegin()}; it != str.rend(); it++)
    {
        reverse += *it;
    }
    return str == reverse ? true : false;
}

int main()
{
    cout << boolalpha;
    cout << isPalindrome(10) << endl;
    return 0;
}