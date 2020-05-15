#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int size{static_cast<int>(nums.size())};
    for (int i{}; i < size; i++)
    {
        if (nums[i] >= target)
            return i;
    }
    return size;
}

int main()
{
    vector<int> nums{1, 3, 5, 6};
    cout << searchInsert(nums, 5) << endl;
    cout << searchInsert(nums, 2) << endl;
    cout << searchInsert(nums, 7) << endl;
    return 0;
}