#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;
    size_t found{haystack.find(needle)};
    return found != string::npos ? static_cast<int>(found) : -1;
}

int main()
{
    cout << strStr("hello", "ll") << endl;
    cout << strStr("aaaaa", "bba") << endl;
    cout << strStr("test", "") << endl;
}