#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (size_t i{digits.size() - 1}; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++; // add one to the same digit
                break;
            }

            if (i == 0)
            {
                digits[i] = 1;
                digits.push_back(0); // add another digit
                break;
            }
            digits[i] = 0;
        }

        return digits;
    }

    void printVector(const vector<int> &vec)
    {
        cout << "[";

        if (vec.empty())
        {
            cout << "]\n";
            return;
        }

        for (int i{}; i < vec.size() - 1; i++)
        {
            cout << vec[i] << ",";
        }
        cout << vec[vec.size() - 1] << "]\n";
    }

    void printInputAndOutputVector(vector<int> &vec)
    {
        cout << "Input: ";
        printVector(vec);
        cout << "Output: ";
        printVector(plusOne(vec));
    }
};

int main()
{
    Solution a;
    vector<int> vec1{1, 2, 3};
    vector<int> vec2{4, 3, 2, 1};
    vector<int> vec3{1, 8, 9};
    vector<int> vec4{1, 9, 9};
    vector<int> vec5{9, 9, 9};

    a.printInputAndOutputVector(vec1);
    a.printInputAndOutputVector(vec2);
    a.printInputAndOutputVector(vec3);
    a.printInputAndOutputVector(vec4);
    a.printInputAndOutputVector(vec5);

    return 0;
}
