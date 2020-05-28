#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int singleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int count{1};
    int prev{}, curr{nums[0]};
    size_t size{nums.size()};
    for (size_t i{1}; i < size; i++)
    {
        prev = curr;
        curr = nums[i];
        if (curr == prev)
        {
            count++;
        }
        else if (count == 1)
        {
            return prev; // the single number was found
        }
        else
        {
            count = 1;
        }
    }

    return curr; // return the last number
}

int main()
{
    vector<int> vec{2, 2, 1};
    vector<int> vec2{4, 1, 2, 1, 2};
    vector<int> vec3{4, 6, 2, 2, 6, 8, 4};
    cout << singleNumber(vec) << endl;
    cout << singleNumber(vec2) << endl;
    cout << singleNumber(vec3) << endl;
    return 0;
}