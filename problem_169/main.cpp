#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums)
{
    size_t size{nums.size()};
    sort(nums.begin(), nums.end());
    int count{1}, majority{nums[0]};
    for (size_t i{1}; i < size; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
        {
            majority = nums[i];
            count = 1;
        }
        if (count > size / 2)
            return majority;
    }
    return majority;
}

int main()
{
    vector<int> vec{3, 2, 3};
    cout << "half of size: " << vec.size() / 2 << endl;
    vector<int> vec2{2, 2, 1, 1, 1, 2, 2};
    cout << "half of size: " << vec2.size() / 2 << endl;
    cout << majorityElement(vec) << endl;
    cout << majorityElement(vec2) << endl;
    return 0;
}